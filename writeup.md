# Fightstick Project
![alt-text](https://github.com/ajinomoto124/FightStickProject/blob/master/DSC00930.jpg?raw=true)
## Write-up
#### Introduction:
I built a custom fightstick tailored for playing Ultra Street Fighter IV on PC.  The buttons and stick are Sanwa arcade parts and everything is wired to an Arduino Micro.  Features include auto-combos and built in option-selects.

#### Design:

######  Materials -
1. 1 12" x 8" x 3/4" Wood*
2. 2 8" x 1-1/2" x 3/4" Wood*
3. 2 8" x 2-1/2" x 3/4" Wood*
4. 1 10-1/2" x 1-1/2" x 3/4" Wood*
5. 2 13-1/2" x 2-1/2" x 3/4" Wood*
6. 2 12" x 8" x .093" Plexiglass Sheets
7. 6 Yellow Sanwa OBSF-30 buttons
8. 2 Black Rim Sanwa OBSF-30 buttons Yellow  
9. 1 Sanwa JLF-TP-8YT-SK OEM RED
10. 1 Sanwa LB-35 Balltop Yellow 
11. 16pc Wire with .110 Quick Disconnect
12. 5-Pin Wiring Harness
13. 4 Yellow Sanwa OBSF 24mm Pushbuttons 
14. 1 Arduino Micro

*all wood is Poplar

###### Hardware-
My design and process for building the box for the fightstick are heavily based off of the tutorial provided by [slagcoin.com](http://www.slagcoin.com/joystick/introduction.html). Tutorial found  [here](http://www.slagcoin.com/joystick/example2.html).  Since I personally own a Qanba fightstick, I based the stick and button layout on the [Q4](http://www.eightarc.com/qanba-q4-white-red/).  I put four top buttons on the back panel away from the player so that the start/home buttons won't be accidentally pressed during play (as shown below) ![alt-text](https://github.com/ajinomoto124/FightStickProject/blob/master/DSC00931.jpg?raw=true).  

I found that the top acrylic sheet and wood panel fit the buttons so snug that I decided not to add screws to hold everything together.  This seemed the most aesthetically pleasing and comfortable for the hands.  My own personal addition to the design from slagcoin.com is the sliding back acrylic panel.  I cut a channel down the inner sides and front wall so that the acrylic sheet can slide in and out for easy access to the internals (below: panel being pulled out).  ![alt-text](https://github.com/ajinomoto124/FightStickProject/blob/master/DSC00935.jpg?raw=true)

Each button was wired to the Arduino with ground on one side and a digital input pin on the other.  Since the buttons took up all of the digital input pins except one and the Sanwa JLF stick outputs digital signal, I wired the stick into the analog pins and read them as digital.  Hardware 30ohm resistors were wired into the Arduino's 5V and each stick pin to allow diagonal inputs to read correctly. 

##### Firmware-
Since the Arduino USB can output to a computer as a keyboard, I realized I could output my controller input to take advantage of certain mechanics within Ultra Street Fighter IV for PC.

https://www.youtube.com/watch?v=aHHoGHcgK9k

#### Testing Methodology:
After soldering all the buttons together, I plugged them into separate locations on the breadboard connected to the arduino.  I tested them for connectvity by holding one end of a multimeter to the grounded port of the arduino and one to the corresponding location while also pressing the button down.  If the multimeter detected a connection while the button was depressed, the connection was solid.  I used the same testing method for the switch's on state.

#### Results and Discussion
In order to comfortably be able to play a first person shooter like quake and still have the street fighter style buttons, the nintendo 64 style layout was necessary.  However, given more time, I would have probably tried to incorporate the third handle in a more smooth and form-fitting manner.

#### Conclusions
Time spend on lab: about 6 hours.
Buttons a switch and two control sticks were attached to a wooden board as a make-shift controller.  Learning how to solder and making mistakes along the way was probably the most time consuming part of this lab.  In the future, it might be better to ensure that everyone in the class can solder properly.
