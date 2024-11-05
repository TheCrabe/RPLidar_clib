/**
  ******************************************************************************
  * @file    rplidar.c
  * @create  2024/04/14
  * @author  LeCrabe
  * @brief   This file contains everything for the RPLidar of the Evolutek team
  ******************************************************************************
  */

// #include "main.h"
#include "rplidar.h"
#include <stdio.h>
#include <string.h>

descriptor new_req(UART_HandleTypeDef *huart, const uint8_t cmd) {
	request req;
	req.start_flag = START1;
	req.command = cmd;
	HAL_UART_Transmit(huart, (uint8_t *)&req, sizeof(req), 100);
	
	descriptor res_desc;
	HAL_UART_Receive(huart, (uint8_t *)&res_desc, 7, 1000);
	return res_desc;
}

health_data get_res_data(UART_HandleTypeDef *huart, const uint16_t size) {
	health_data res_data_struct;
	HAL_UART_Receive(huart, (uint8_t *)&res_data_struct, size, 1000);
	return res_data_struct;
}

// No response
int stop(UART_HandleTypeDef *huart) {
	new_req(&huart, STOP);

	return 0;
}
int reset(UART_HandleTypeDef *huart) {
	new_req(&huart, RESET);
	
	return 0;
}

// Multiple response
scan(UART_HandleTypeDef *huart) {
	descriptor res_desc = new_req(&huart, SCAN);
}
// force_scan(UART_HandleTypeDef *huart) {
	// descriptor res_desc = new_req(&huart, FORCE_SCAN);
// }
// express_scan(UART_HandleTypeDef *huart) {
	// descriptor res_desc = new_req(&huart, EXPRESS_SCAN);
// }

// Single response
info_data get_info(UART_HandleTypeDef *huart) {
	descriptor res_desc = new_req(&huart, GET_INFO);

	info_data res_data;
	HAL_UART_Receive(huart, (uint8_t *)&res_data, sizeof(res_data), 1000);

	return res_data;
}
health_data get_health(UART_HandleTypeDef *huart) {
	descriptor res_desc = new_req(&huart, GET_HEALTH);
	
	health_data res_data;
	HAL_UART_Receive(huart, (uint8_t *)&res_data, sizeof(res_data), 1000);

	return res_data;
}
samplerate_data get_samplerate(UART_HandleTypeDef *huart) {
	descriptor res_desc = new_req(&huart, GET_SAMPLERATE);
	
	samplerate_data res_data;
	HAL_UART_Receive(huart, (uint8_t *)&res_data, sizeof(res_data), 1000);

	return res_data;
}
// lidar_conf_data get_lidar_conf(UART_HandleTypeDef *huart) {
// 	descriptor res_desc = new_req(&huart, GET_LIDAR_CONF);
	
// 	lidar_conf_data res_data;
// 	HAL_UART_Receive(huart, (uint8_t *)&res_data, sizeof(res_data), 1000);

// 	return res_data;
// }