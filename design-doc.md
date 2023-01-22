# Design doc for the application

The application shall be split into independent, extensible and composable
subsystems. 

First, there should be
- replay sub-system,
- data aquisition sub-system,
- plotting sub-system,
- calibration algorithms sub-system.

We should start from the user experience and work the way backward 
to the technical details.

Replay functionality
-----------------------
A user shall be able to replay the pre-recorded data.
A user shall be able to generate synthetic data and then replay it,
or generate it on the fly.
Sensor models are created, which can be used to generate the synthetic data.

When replaying, a user shall be able to change at run-time the size of the
data buffer.

