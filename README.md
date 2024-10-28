# RPLidar_clib
c lib to operate RPLidar

## Request
### Paquet format
Send in less than 5s

|    Start Flag     | [Command](#command-type)  | Payload Size | Payload Data | [Checksum](#checksum) |
|:-----------------:|:-------------------------:|:------------:|:------------:|:---------------------:|
|     Required      |         Required          |  Optionnal   |  Optionnal   |       Optionnal       |
|   1 byte (0xA5)   |          1 byte           |    1 byte    | 0-255 bytes  |        1 byte         |
--> Transmission order

### Command type

|  Request Name  | Value | Payload |   Response Mode   |                                RPLIDAR Operation                               | Supported Firmware version |
|:--------------:|:-----:|:-------:|:-----------------:|:------------------------------------------------------------------------------:|:----:|
|      STOP      | 0x25  |   N/A   |    No response    |                Exit the current state and enter the idle state                 | 1.0  |
|     RESET      | 0x40  |   N/A   |    No response    |                         Reset(reboot) the RPLIDAR core                         | 1.0  |
|      SCAN      | 0x20  |   N/A   | Multiple response |                           Enter the scanning state                             | 1.0  |
|  EXPRESS_SCAN  | 0x82  |   Yes   | Multiple response |           Enter the scanning state and working at the highest speed            | 1.7  |
|   FORCE_SCAN   | 0x21  |   N/A   | Multiple response | Enter the scanning state and force data output without checking rotation speed | 1.0  |
|    GET_INFO    | 0x50  |   N/A   |  Single response  |                Send out the device info (e.g. serial number)                   | 1.0  |
|   GET_HEALTH   | 0x52  |   N/A   |  Single response  |                      Send out the device health info                           | 1.0  |
| GET_SAMPLERATE | 0x59  |   N/A   |  Single response  |                       Send out single sampling time                            | 1.17 |
| GET_LIDAR_CONF | 0x84  |   Yes   |  Single response  |                          Get LIDAR configuration                               | 1.24 |

### Checksum
XOR = ^
checksum = 0 ^ 0xA5 ^ CmdType ^ PayloadSize ^ Payload[0] ^ ... ^ Payload[n]

## Response descriptor

## Data response