/**
  ******************************************************************************
  * @file    rplidar.c
  * @create  2024/04/14
  * @author  LeCrabe
  * @brief   This file contains everything for the RPLidar of the Evolutek team
  ******************************************************************************
  */

#include "main.h"
#include "rplidar.h"
#include <stdio.h>
#include <string.h>

request new_req(UART_HandleTypeDef *huart, const uint8_t cmd) {
	request req_struct;
	req_struct.start_flag = START1;
	req_struct.command = cmd;
	if (cmd > 0x80) {

	}
	HAL_UART_Transmit(huart, (uint8_t *)&req_struct, sizeof(req_struct), 100);
	return req_struct;
}

descriptor get_res_descriptor(UART_HandleTypeDef *huart) {
	descriptor res_descriptor_struct;
	HAL_UART_Receive(huart, (uint8_t *)&res_descriptor_struct, 7, 1000);
	return res_descriptor_struct;
}

health_data get_res_data(UART_HandleTypeDef *huart) {
	health_data res_data_struct;
	HAL_UART_Receive(huart, (uint8_t *)&res_data_struct, 3, 1000);
	return res_data_struct;
}
