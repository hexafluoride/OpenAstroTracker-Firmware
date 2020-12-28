#include "RotationAxis.hpp"

#include "Arduino.h"

RotationAxis::RotationAxis(
    const float transmission,
    Driver &driver) : transmission(transmission),
                      driver(driver) {}

void RotationAxis::setup()
{
    driver.setup();
}

void RotationAxis::loop()
{
    
    driver.step();

    // if (!accelStepper.run())
    // {
    //     onTargetReached();
    // }
}

void RotationAxis::rotate(const float degPerSecond)
{
    // accelStepper.setSpeed(getStepsPerDeg() * speed);
}

void RotationAxis::rotateToTarget(const float degPerSecond, const float target)
{
    // accelStepper.setSpeed(getStepsPerDeg() * speed);
    // accelStepper.moveTo(getStepsPerDeg() * target);
}

void RotationAxis::onTargetReached()
{
    // default implementation for the case if the specific axis implementation does not need this callback
}

float RotationAxis::getStepsPerDeg() const
{
    return transmission * driver.getStepperSpecs().getStepsPerRevolution() * driver.getMicrostepping() / 360.0f;
}

float RotationAxis::getCurrentPosition() const
{
    return currentPosition;
}

void RotationAxis::setCurrentPosition(float degrees)
{
    currentPosition = degrees;
}