#!/usr/bin/php
<?php
/**
 * Connects to a network socket and waits for weather data sent by an
 * Arduino running the WeatherStationReceiver program. Values for
 * temperature and humidity are extracted and posted to a Twitter
 * account as updates.
 *
 * Copyright 2009 Jonathan Oxer <jon@oxer.com.au>
 * Copyright 2009 Hugh Blemings <hugh@blemings.org>
 *  http://www.practicalarduino.com/projects/weather-station-receiver
 */

// Set Twitter credentials
$twitter_username = "abc123";  // Replace with your Twitter username
$twitter_password = "abc123";  // Replace with your Twitter password

// Configure the serial-to-socket proxy connection to the Arduino
$arduino_host = "localhost";
$arduino_port = "5331";

$update_interval = 600;   // Minimum number of seconds between updates (10 mins)
$last_update_temp = 0;
$last_update_relh = 0;

// Connect to the Arduino
$fp = fsockopen( "tcp://".$arduino_host, $arduino_port, $errno, $errstr, 30 );
stream_set_timeout( $fp, 3000 );

// Watch for changes
while (!feof($fp)) {
	$rawdata = fgets($fp, 200);
	//echo "raw: $rawdata\n";   // Uncomment to watch the raw data stream
	$sample = explode( "=", $rawdata );
	$dataParam = trim( $sample[0] );
	$dataValue = trim( $sample[1] );

	if( strlen( $dataValue ) > 0 )
	{
		switch( $dataParam )
		{
			case "TEMPERATURE":
				if( date("U") - $last_update_temp > $update_interval )
				{
					$message = "The temperature outside is {$dataValue}C";
					$command = "curl -u $twitter_username:$twitter_password -d status=\"$message\" http://twitter.com/statuses/update.xml";
					shell_exec( $command );
					$last_update_temp = date("U");
				}
			break;
			case "HUMIDITY":
				if( date("U") - $last_update_relh > $update_interval )
				{
					$message = "The relative humidity outside is {$dataValue}%";
					$command = "curl -u $twitter_username:$twitter_password -d status=\"$message\" http://twitter.com/statuses/update.xml";
					shell_exec( $command );
					$last_update_relh = date("U");
				}
			break;
		}
	}
}
fclose($fp);
?>
