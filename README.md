# Low Pass Filter(LPF) Example

## Introduction
Actually, many actuators like motors do not have high responsiveness. For example, if you move a fixed motor to 2000 RPM, this excessive motion can cause the motor to lose steps. Therefore, when driving these devices, it may be a good idea to use a low-pass filter (LPF) instead of designing the appropriate acceleration and deceleration logic. This program simulates how the LPF works with acceleration and deceleration functions on RTOS-based systems.

## Modeling
In most cases, the actuator driver software does not operate standalone. For example, the front-end software translates physical inputs (such as the speed of the vehicle cluster) into angles, which the motor driver takes as input to move certain actuators. In addition, these tasks are run as a cyclical task on the RTOS. For example, the driver runs in a 1ms job and the front-end logic runs in a 10ms job. This program follows this model:

1. The 10ms task uses the PT1 damping filter to convert the input to a damped value.
2. The 1ms task accepts PT1 damped output as input and passes them through the 1st and 2nd-order LPFs.

In this model, three LPFs are used. PT1 LPF, 1st-order LPF, and 2nd-order LPF.

### PT1 damping LPF
For detailed description of this filter, please see [this link](https://infosys.beckhoff.com/english.php?content=../content/1033/tcplclibbabasic/html/tcplclibbabasic_pt2.htm&id=)
This filter is used to soften the input changes to obtain smooth output.

### 1st-order LPF
For detailed description of this filter, please see [this document](https://github.com/hcyang1012/Filter_Example/raw/master/docs/002-04780_AN204780_F2MC_16FX_Family_Stepper_Motor_Controller.pdf)
Actually, this filter is very similar to the PT1 damping filter. They soften the stop point of the end. However, drastic acceleration is still required in the motor example because they can not smooth the starting point of the input. 

### 2nd-order LPF
The 2nd-order LPF is used to address the problem of the pervious filters. In fact, the 2nd-order LPF is exactly the same as the 1st-order LPF. This is just a connection of two 1st-order LPFs. This simple connection can smooth the starting point of the input.

## Simulation Example
There are two simulation examples in this program.
1. Static input (1000)
This example shows how the initial input changes as it passes through each filter. In particular, you can see that the lst-order LPF softens the stopping point while the 2nd-order LPF smoothes the starting point.
![N=6 Example](https://github.com/hcyang1012/Filter_Example/raw/master/samples/N_6_SimpleInput.png)

2. Random input
This example shows how the motor can move smoothly without losing steps. In particular, you can see that the filters allow the motor to withstand sudden changes in input.
![N=6 Random Example](https://github.com/hcyang1012/Filter_Example/raw/master/samples/N_6_RandomInput.png)

## Conclusion
This program shows how three types of LPFs works. The PT1 and lst-order LPFs soften the stopping point while the 2nd-order LPF smoothes the starting point. With these filters, you can simply design an actuator system without designing complex acceleration and deceleration algorithms.
