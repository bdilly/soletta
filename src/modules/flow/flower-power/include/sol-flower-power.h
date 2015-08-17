/*
 * This file is part of the Soletta Project
 *
 * Copyright (C) 2015 Intel Corporation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 *   * Neither the name of Intel Corporation nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include "sol-flow.h"
#include "sol-flow-packet.h"
#include "sol-types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* PLANT INFORMATION */

struct sol_flower_power_data {
    struct sol_drange fertilizer;
    struct sol_drange light;
    struct sol_drange temperature;
    struct sol_drange water;
    /* TODO: maybe convert it to int */
    char *timestamp;
    char *id;
};

extern const struct sol_flow_packet_type *PACKET_TYPE_FLOWER_POWER;

struct sol_flow_packet *sol_flower_power_new_packet(const struct sol_flower_power_data *fpd);
struct sol_flow_packet *sol_flower_power_new_packet_components(const char *id, const char *timestamp, struct sol_drange *fertilizer, struct sol_drange *light, struct sol_drange *temperature, struct sol_drange *water);

int sol_flower_power_get_packet(const struct sol_flow_packet *packet, struct sol_flower_power_data *fpd);
int sol_flower_power_get_packet_components(const struct sol_flow_packet *packet, const char **id, const char **timestamp, struct sol_drange *fertilizer, struct sol_drange *light, struct sol_drange *temperature, struct sol_drange *water);

int sol_flower_power_send_packet(struct sol_flow_node *src, uint16_t src_port, const struct sol_flower_power_data *fpd);
int sol_flower_power_send_packet_components(struct sol_flow_node *src, uint16_t src_port, char *id, char *timestamp, struct sol_drange *fertilizer, struct sol_drange *light, struct sol_drange *temperature, struct sol_drange *water);

/* SENSOR INFORMATION */

struct sol_flower_power_sensor_data {
    struct sol_drange battery_level;
    char *battery_end_of_life;
    char *id;
    char *timestamp;
};

extern const struct sol_flow_packet_type *PACKET_TYPE_FLOWER_POWER_SENSOR;

struct sol_flow_packet *sol_flower_power_sensor_new_packet(const struct sol_flower_power_sensor_data *fpsd);
struct sol_flow_packet *sol_flower_power_sensor_new_packet_components(const char *id, const char *timestamp, const char *battery_end_of_life, struct sol_drange *battery_level);

int sol_flower_power_sensor_get_packet(const struct sol_flow_packet *packet, struct sol_flower_power_sensor_data *fpsd);
int sol_flower_power_sensor_get_packet_components(const struct sol_flow_packet *packet, const char **id, const char **timestamp, const char **battery_end_of_life, struct sol_drange *battery_level);

int sol_flower_power_sensor_send_packet(struct sol_flow_node *src, uint16_t src_port, const struct sol_flower_power_sensor_data *fpsd);
int sol_flower_power_sensor_send_packet_components(struct sol_flow_node *src, uint16_t src_port, char *id, char *timestamp, char *battery_end_of_life, struct sol_drange *battery_level);

#ifdef __cplusplus
}
#endif
