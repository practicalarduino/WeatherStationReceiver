#ifndef WSR_H_
#define WSR_H_
/*--------------------------------------------------------------------------------------
 Function Declarations
--------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------
 Defines
--------------------------------------------------------------------------------------*/
// Type aliases for brevity in the actual code
typedef unsigned int       uint; //16bit
typedef signed int         sint; //16bit

// Some convenience constants
#define  ASCIINUMBASE      0x30  //base value for ascii number '0'
#define  CHAR_CR           0x0D  //carriage return character
#define  CHAR_LF           0x0A  //line feed character

#define WSR_TIMER_PERIOD_US          4                            //Timer1 resolution is 4uS
//master period width filter
#define WSR_PERIOD_FILTER_MIN        ( 300/WSR_TIMER_PERIOD_US)   //min 300uS  allowed through filter
#define WSR_PERIOD_FILTER_MAX        (1800/WSR_TIMER_PERIOD_US)   //max 1800uS allowed through filter
//detection of a 'SHORT', nominal 367uS
#define WSR_SHORT_PERIOD_MIN         WSR_PERIOD_FILTER_MIN        //
#define WSR_SHORT_PERIOD_MAX         ( 600/WSR_TIMER_PERIOD_US)   //max 600uS for a "SHORT"
//detection of a 'LONG', nominal 1464uS
#define WSR_LONG_PERIOD_MIN          (1200/WSR_TIMER_PERIOD_US)   //min 1200uS for a "LONG"
#define WSR_LONG_PERIOD_MAX          WSR_PERIOD_FILTER_MAX        //

//bICP_WSR_State
#define WSR_STATE_IDLE                  0   //any junk, invalid pulse widths or timeout should all return to this state
#define WSR_STATE_LOADING_BITSTREAM     1   //got an initial 0, loading and checking bitstream

#define WSR_BIT_NONE                    0   //
#define WSR_BIT_ZERO                    1   //
#define WSR_BIT_ONE                     2   //

#define WSR_PACKETARRAYSIZE             8   //
#define WSR_TIMESTAMP_BIT_OFFSET       (4*8)//the timestamp takes up the first 32 bits (4 bytes) of the packet
#define WSR_RFPACKETBITSIZE             52  //52 bits in an RF packet (not including the post-generated timestamp)

#define WSR_RESET()                    { bICP_WSR_State = WSR_STATE_IDLE; bICP_WSR_PacketInputBitPointer = WSR_TIMESTAMP_BIT_OFFSET; }

/*--------------------------------------------------------------------------------------
 General macros
--------------------------------------------------------------------------------------*/
#define INPUT_CAPTURE_IS_RISING_EDGE()    ((TCCR1B & _BV(ICES1)) != 0)
#define INPUT_CAPTURE_IS_FALLING_EDGE()   ((TCCR1B & _BV(ICES1)) == 0)
#define SET_INPUT_CAPTURE_RISING_EDGE()   (TCCR1B |=  _BV(ICES1))
#define SET_INPUT_CAPTURE_FALLING_EDGE()  (TCCR1B &= ~_BV(ICES1))

#define GREEN_TESTLED_IS_ON()       ((PORTD & (1<<PORTD6)) == 0)
#define GREEN_TESTLED_IS_OFF()      ((PORTD & (1<<PORTD6)) != 0)
#define GREEN_TESTLED_ON()          ((PORTD &= ~(1<<PORTD6)))
#define GREEN_TESTLED_OFF()         ((PORTD |=  (1<<PORTD6)))
#define GREEN_TESTLED_TOGGLE()      if(GREEN_TESTLED_IS_ON()){GREEN_TESTLED_OFF();}else{GREEN_TESTLED_ON();}

#define RED_TESTLED_IS_ON()         ((PORTD & (1<<PORTD7)) == 0)
#define RED_TESTLED_IS_OFF()        ((PORTD & (1<<PORTD7)) != 0)
#define RED_TESTLED_ON()            ((PORTD &= ~(1<<PORTD7)))
#define RED_TESTLED_OFF()           ((PORTD |=  (1<<PORTD7)))
#define RED_TESTLED_TOGGLE()        if(RED_TESTLED_IS_ON()){RED_TESTLED_OFF();}else{RED_TESTLED_ON();}

#endif /*WSR_H_*/
