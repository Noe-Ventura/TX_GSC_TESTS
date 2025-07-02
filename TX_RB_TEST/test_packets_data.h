#include <stdint.h>
#include "PacketDefinition_Firehorn.h"

// Configuration of the different test packets

/////////////////////////////////////////////////////////////////
// ----------------------- GSE PACKETS ----------------------- //
/////////////////////////////////////////////////////////////////
GSE_cmd_status gse_cmd_status_packet = {
    .fillingN2O = 1,
    .vent = 0};

PacketGSE_downlink gse_down_packet = {
    .tankPressure = 101.3f,
    .tankTemperature = 25.0f,
    .fillingPressure = 100.0f,
    .status = {
        .fillingN2O = 1,
        .vent = 0},
    .disconnectActive = true,
    .loadcellRaw = 12345};

/////////////////////////////////////////////////////////////////
// ---------------------- AV PACKETS ------------------------  //
/////////////////////////////////////////////////////////////////

engine_state_t av_engine_state_down_packet = {
    .igniter_LOX = 1,
    .igniter_fuel = 0,
    .main_LOX = 1,
    .main_fuel = 1,
    .vent_LOX = 0,
    .vent_fuel = 1};

av_uplink_t av_up_packet = {
    .order_id = AV_CMD_IGNITION,
    .order_value = 1};

// Strange value because of the resolution of the packet
av_downlink_t av_down_packet = {
    .packet_nbr = 46,

    .gnss_lon = (int32_t)(6.1234 * 1000),  // 6.123° -> 61234
    .gnss_lat = (int32_t)(46.9876 * 1000), // 46.987° -> 46987
    .gnss_alt = (uint16_t)(500.0 / 10),    // 500m -> 50 (10m resolution)

    .gnss_vertical_speed = (int8_t)(55 / 10), // 5.5 km/h -> 

    .N2_pressure = (uint16_t)(50.0 * 2),   // 50 bar -> 100 (0.5 bar resolution)
    .fuel_pressure = (uint16_t)(51.0 * 2), // 51 bar -> 102
    .LOX_pressure = (uint16_t)(52.0 * 2),  // 52 bar -> 104

    .fuel_level = (uint8_t)(75.0 / 0.25), // 75 L -> 300
    .LOX_level = (uint8_t)(80.0 / 0.25),  // 80 L -> 320

    .N2_temp = 20,
    .LOX_temp = 22,
    .LOX_inj_temp = 26,

    .lpb_voltage = (uint8_t)(3.3 * 4),
    .hpb_voltage = (uint8_t)(3.3 * 4),

    .av_fc_temp = 25,
    .ambient_temp = 22,

    .engine_state = ENGINE_STATE_IGN_LOX | ENGINE_STATE_MAIN_LOX | ENGINE_STATE_MAIN_FUEL,
    .av_state = 3,
    .cam_rec = CAMERA_REC_PARACHUTE};

// Utilisée dans le main.cpp
extern engine_state_t av_engine_state_down_packet;
extern av_uplink_t av_up_packet;
extern av_downlink_t av_down_packet;
extern GSE_cmd_status gse_cmd_status_packet;
extern PacketGSE_downlink gse_down_packet;
