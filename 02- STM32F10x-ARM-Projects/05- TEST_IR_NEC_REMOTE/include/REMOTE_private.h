/********************************************************************/
/*  Author   : Mohamed Maged                                        */
/*  Version  : V01                                                  */
/*  Date     : 1 October 2023                                       */
/*  Logs     : V01 : Initial Creation                               */
/********************************************************************/
#ifndef REMOTE_PRIVATE_H
#define REMOTE_PRIVATE_H

#define NULL        ((void *)0)



/* Recieved Frame bits for NEC REMOTE */
#define  ADDRESS_BIT             0 
#define  ADDRESS_INVERTED_BIT    8
#define  DATA_BIT                16
#define  DATA_INVERTED_BIT       24

/* Frame Errors */
#define   FRAME_CORRECT          1
#define   FRAME_ERROR            0

/* Buttons data ID [NEC REMOTE]  */
#define     POWER                69
#define     MODE                 70
#define     MUTE                 71
#define     PLAY_RESUME          68
#define     LEFT                 64
#define     RIGHT                67
#define     EQ                   7
#define     VOLUME_DOWN          21
#define     VOLUME_UP            9
#define     ZERO                 22
#define     RPT                  25
#define     U_SD                 13
#define     ONE                  12
#define     TWO                  24
#define     THREE                94
#define     FOUR                 8
#define     FIVE                 28
#define     SIX                  90
#define     SEVEN                60
#define     EIGHT                82
#define     NINE                 74

/******* Private functions prototypes ******/
static u8 REMOTE_u8CheckFrame(void);


#endif
