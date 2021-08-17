/*
 * fan_state.h
 *
 *  Created on: Aug 17, 2021
 *      Author: horance
 */

#ifndef H448821D8_451A_4032_B9C1_886B0F243819
#define H448821D8_451A_4032_B9C1_886B0F243819

#include "status.h"

struct FanState {
    enum State {
        INIT, READY, ERROR,
    };
    
    Status Transfer(State from, State to);

    bool IsInit() const;
    bool IsReady() const;
    bool IsError() const;

private:
    Status Ok(State to);
    Status Error(Status status);

private:
    State state = INIT;
};

#endif /* H448821D8_451A_4032_B9C1_886B0F243819 */
