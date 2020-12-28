#pragma once

#include "../stepper/StepperSpecs.hpp"

#include "stdint.h"
#include "AccelStepper.h"

/**
 * This is the abstract interface to be implemented by specific driver implementations.
 * The interface itself is kept to a minimum to provide easy extensions by new hardware.
 * All the parameters required for correct setup and operation of the actual driver should
 * be provided in its constructor (dependency injection).
 */
class Driver
{
public:
    enum Direction
    {
        CLOCKWISE = 1,
        ANTICLOCKWISE = -1
    };

    template<class T>
    static T* create();

    /**
     * Construct new driver with provided hardware specifications.
     * 
     * stepper - reference to the stepper specifications
     */
    Driver(const StepperSpecs &stepper);

    /**
     * Perform required preparations (e.g. setting up UART connection, max speed,
     * microstepping etc.)
     */
    virtual void setup() = 0;

    /**
     * Return specs of the connected stepper.
     */
    const StepperSpecs &getStepperSpecs() const;

    /**
     * Return available microstepping modes as bitmask of 16 bits. Modes are 
     * represented from lowest to highest bit (1,2,4,8,16,32,64,128,256...) respectively.
     * E.g. 0000_0000_0000_1011 stands for available modes: full step, half step and 8.
     * If microstepping is not supported, this function will return value 1.
     */
    virtual uint16_t getAvailableMicrosteppingModes() const = 0;

    /**
     * Set microstepping. The value has to be power of 2 between 1 and 256.
     */
    void setMicrostepping(const uint16_t microstepping);

    /**
     * Get currently selected microstepping mode.
     */
    uint16_t getMicrostepping() const;

    /**
     * Return maximal speed (steps per second) taking microstepping and driver characteristics into account.
     */
    virtual uint16_t getMaxSpeed() const = 0;

    /**
     * Perform a step in the currently set direction.
     */
    virtual void step() = 0;

    virtual void setDirection(Direction direction) = 0;

protected:
    virtual void updateMicrostepping(uint16_t microstepping) = 0;

    const StepperSpecs &stepper;

    uint16_t microstepping;

    Direction direction = CLOCKWISE;
};
