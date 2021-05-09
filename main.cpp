// /* mbed Microcontroller Library
//  * Copyright (c) 2019 ARM Limited
//  * SPDX-License-Identifier: Apache-2.0
//  */

// // #include "Callback.h"
// // #include "UnbufferedSerial.h"
// #include "XBeeLib.h"
// #include "mbed.h"
// // #include <cstdint>
//  #define WAIT_TIME_MS 3000 



// DigitalOut led1(LED1);

// static UnbufferedSerial ser(p13, p14);

// void send_data(uint8_t data[]){
//     if (ser.writable()){
//         int i = 0;
//         printf("Sending data...\n");
//         while(data[i]!='\n'){
//             ser.write(&data[i], 1);
//             i++;
//         }
        
//     }
// }

// void recv_data_cb(){
//     uint8_t data,
//     i=0;
//     printf("Reading %ld bytes...\n", ser.size());

//     while (ser.readable()) {
//         ser.read(&data, 1);
//         printf(" %1x",data);
//         i --;
//     }    
//     printf("\nBytes left %ld \n", ser.size());
    
// }


// int main()
// {
//     printf("This is the bare metal blinky example running on Mbed OS %d.%d.%d.\n", MBED_MAJOR_VERSION, MBED_MINOR_VERSION, MBED_PATCH_VERSION);
//     // uint8_t pl;
//      uint8_t data[] = "ola";
//      XBeeLib::XBeeZB xbee(RADIO_TX, RADIO_RX, RADIO_RESET, NC, NC, 9600);
//      XBeeLib::RadioStatus radioStatus = xbee.init();
//     // xbee.get_power_level(&pl);
//      xbee.send_data_to_coordinator((const uint8_t *)data, sizeof(data));
    
//     // printf("%d",pl);
//     ser.baud(9600);
//     ser.format(
//         /* bits */ 8,
//         /* parity */ SerialBase::None,
//         /* stop bit */ 1
//     );
//     uint8_t data_send[] = {
        
//         0x7E,   /*Starte delimiter*/
//         0x00,   /**/
//         0x11,   /**/
//         0x10,   /**/
//         0x01,   /**/
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    /**/
//         0xFF, 0xFE, /**/
//         0x00,   /**/
//         0x00,   /**/
//         0x6F, 0x6C, 0x61,   /**/
//         0xB5,   /**/
//         0x0A
//     };
//     uint8_t atCmdId [] = {
//         0x7E,
//         0x00,
//         0x04,
//         0x08,
//         0x01,
//         0x49,
//         0x44,
//         0x69,
//         0x0A
//     };
//     ser.attach(recv_data_cb, SerialBase::RxIrq);
//     thread_sleep_for(500);
    
//     while (true) {
//         led1 = !led1;
//         send_data(atCmdId);

//         thread_sleep_for(WAIT_TIME_MS);
//     }
// }

// #include "mbed.h"
// #include "XBeeLib.h"
// #include <cstdint>
// #include <cstdio>


// int main(){
//     XBeeLib::XBeeZB xbee(RADIO_TX, RADIO_RX, RADIO_RESET, NC, NC, 9600);
//     while(xbee.init() != 0){
//         printf("\nfalha ao inicializar\n");
//     }
//     printf("inicializou\n");
//     xbee.send_data_to_coordinator((uint8_t *)"Ola", 3);
    
// }

// #include "mbed.h"
// #include "XBEE.h"
// #include "mbed_thread.h"
 
// XBEE xbee(p13,p14);;
 
// void receive(void) {
//     xbee.recvAttach();
// }
// int main(){
    
//     xbee.init();
//     xbee.set_cfg((char *)"PL", 1);
//     printf("\nNI: %s\n",xbee.NI);
//     printf("ID: %x\n", xbee.ID);
//     printf("MY: %x\n", xbee.MY);
//     printf("SH: %x\n", xbee.SH);
//     printf("SL: %x\n", xbee.SL);
//     printf("PL: %x\n", xbee.PL);
//     printf("BD: %x\n", xbee.BD);
//     printf("AO: %x\n", xbee.AO);
//     printf("DB: %x\n", xbee.DB);
//     printf("TP: %x\n", xbee.TP);
//     while(1){
//         xbee.send_msg((char *)"AGORAVAI1", XBEE_COORD);
//         thread_sleep_for(500);
//     }

// }

#include "mbed.h"
#include "XBeeLib.h"
#include "mbed_thread.h"
#include <cstdint>
#include <cstdio>


int main(){
    XBeeLib::XBeeZB xbee(RADIO_TX, RADIO_RX, RADIO_RESET, NC, NC, 9600);
    while(xbee.init() != 0){
        printf("\nfalha ao inicializar\n");
        thread_sleep_for(500);
    }
    printf("inicializou\n");
    xbee.send_data_to_coordinator((uint8_t *)"Ola!", 4);
    
}