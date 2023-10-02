/*****************************************************/
 /* Author      : mosad                              */
 /* Version     : v01                                */
 /* date        : 31/8/2020                          */
/*****************************************************/
#ifndef REMOTE_PRIVATE_H
#define REMOTE_PRIVATE_H




/* Frame bits */
#define  ADDRESS_BIT           0 
#define  ADDRESS_INVERTED_BIT  8
#define   DATA_BIT              16
#define  DATA_INVERTED_BIT     24

/* Errors */
#define   FRAME_CORRECT   1
#define   FRAME_ERROR     0

/* Buttons data ID */
#define     POWER            69
#define     MODE             70
#define     MUTE             71
#define     PLAY_RESUME      68
#define     RIGHT            64
#define     LEFT             67
#define     EQ               7
#define     VOLUME_DOWN      21
#define     VOLUME_UP        9
#define     ZERO             22
#define     RPT              25
#define     U_USD            13
#define     ONE              12
#define     TWO              24
#define     THREE            94
#define     FOUR             8
#define     FIVE             28
#define     SIX              90
#define     SEVEN            60
#define     EIGHT            82
#define     NINE             74

static u8 REMOTE_u8CheckFrame(void);



#endif
