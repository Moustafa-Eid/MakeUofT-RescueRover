# MakeUofT Makeathon Project - RescueRover

## Check out our devpost for pics and more info!
## Devpost: https://devpost.com/software/rescue-rover

## Inspiration
Our team recognizes that the world of today is run on data. This data can be provided from people on the field, but in a stressful environment, anything can happen. This is why our group came together to provide a service for professional search and rescue teams. These professionals can now receive precise and practical data instantly with the _Rescue Rover_. When lives are on the line, its important that all relevant information is taken into account. 

## What it does
The _Rescue Rover_ can be controlled with a remote to traverse dangerous environments. Lets take a burning building for example. The firefighter would use the rover to search the house for danger zones of high density fire and potential survivors trapped in the house. If the firefighters knew the layout of the house and the location of survivors, they could navigate the fire more efficiently and effectively. The _Rescue Rover_ will provide the team with all the information to make an informed decision on how to proceed with the rescue. 

Continuing from the burning building example, the flame sensor tracks the location of the fire. The temperature and humidity sensor tracks the intensity of the fire and potential future zones of risk. The camera attached to a servo will recognize survivors and alert the firefighters of their location. All of this tracked data will be sent to a Solace cloud and thus will be ready to be reviewed and processed.

## How I built it
First off, we built the car using geared motors, motor drivers, and an rc chasis. We started by soldering the wires to our motors and wrapping them with tape. Then, we had to cut out a front stand to keep the car upright since we only had two wheels to work with. Finally, we had to glue everything together and make sure the car was symmetrical. 

Next was the hardware. We started by testing each individual sensor we wanted to use. Then we used the raw input data from the sensors to calculate the refined output is more useful. We tested the raspberry pi with the Telus board to test its capabilities and how we could implement it in our project. After we finished each component separately, we combined the sensor logic into one file and sent it up to the cloud. 

We then worked on using a remote controller to control the functions of the car. Pyusb was used to interface with the external keyboard and drive the wheels according to use input.

We utilized the Telus IoT Shield to get LTE connection to the RC Car so that it is always online. We then used Solace's Cloud to control the car by sending controller inputs from a laptop to the pi on the car over the cloud. We also accepted the sensor inputs to the cloud from the pi and sent them over to the laptop to see.

## Challenges I ran into
We ran into some problems trying to set up new environments on unfamiliar boards. It turns out that it was faulty and the replacement board was not calibrated with linux which meant we needed to install it before we could proceed. 

One of the temperature sensors had inverse behaviour to what we were expecting. This led us to use a different temperature sensor which included a humidity sensor. 

Learning how to work with Solace environment and editing with JSON files. It took time to get everything set up for the Telus IoT shield. 

## Accomplishments that I'm proud of
Finally setting up Solace's routing system. Completing the rc Car for a demo. 

## What I learned
I learned how to connect software and hardware together using physical connections. I learned about I2C protocol and SPI connections. I learned how to use a variety of different sensors and then interpret its raw data. We learned how to work inside of the Solace environment. We gained more experience with working with JSON files and forged a stronger understanding of connectivity between devices. 

## What's next for Rescue Rover
More sensors need to be added for increased data output. Better movement is something that can be improved. A live webcam feed that will be able to map out a room in a matter of seconds. Image analysis and facial recognition.
