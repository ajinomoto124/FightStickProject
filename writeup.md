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
Since the Arduino USB can output to a computer as a keyboard, I realized I could output my controller input to take advantage of certain mechanics within Ultra Street Fighter IV for PC.  In the Arduino INO, I set each button input to correspond to a keyboard letter output and directions on the stick to be mapped to w, s, left shift, and right shift (up, down, left, right).In Street Fighter I changed the game options for button settings to correspond to the keyboard keys that are pressed via the controller.  Additionally, I have dubbed the two rightmost buttons on the stick the "Attack Option" and "Defense Option" buttons.  When another of the six buttons is pressed in combination with one of these two buttons I programmed in a separate series of commands to execute (more explained below).  Click on the image below to be taken to the youtube video of the button demo.

<a href="http://www.youtube.com/watch?feature=player_embedded&v=DyG9BGCO_4Y
" target="_blank"><img src="http://img.youtube.com/vi/DyG9BGCO_4Y/0.jpg" 
alt="IMAGE ALT TEXT HERE" width="240" height="180" border="10" /></a>

The simplest thing I decided to take advantage of was the ability to send a sequence of inputs to the computer.  Instead of having to manually roll the stick in a quarter circle fashion (down, down-right, right) to get a hadouken (fireball) to execute, the user simply has to press the punch button and my Attack Option button.  Video link comparing the inputs is below.

<a href="http://www.youtube.com/watch?feature=player_embedded&v=mz11ff9VXdY
" target="_blank"><img src="http://img.youtube.com/vi/mz11ff9VXdY/0.jpg" 
alt="IMAGE ALT TEXT HERE" width="240" height="180" border="10" /></a>

Similarly I used this to input both Evil Ryu's super (first video below) and a combo that includes a 1-frame link(second video below).  A 1-frame link in a Street Fighter combo requires a button input to take place exactly on a specific frame of the game.  Since the game itself runs at 60 fps, this means that the input requires precision to 1/60th a second or about 16.67 milliseconds.  To a normal player this can be difficult to pull off consistently, but my controller is precise to the millisecond and can hit this combo with ease.  The player just has to press the Heavy Punch button and the Attack Option button together to execute this combo.

<a href="http://www.youtube.com/watch?feature=player_embedded&v=4ihFlOGaQrM
" target="_blank"><img src="http://img.youtube.com/vi/4ihFlOGaQrM/0.jpg" 
alt="IMAGE ALT TEXT HERE" width="240" height="180" border="10" /></a>
<a href="http://www.youtube.com/watch?feature=player_embedded&v=MLHcEO_MvnY
" target="_blank"><img src="http://img.youtube.com/vi/MLHcEO_MvnY/0.jpg" 
alt="IMAGE ALT TEXT HERE" width="240" height="180" border="10" /></a>

Lastly, my fightstick implements 2 defensive options that make use of the games input leniency mechanics.  The fighting game community has coined the term option-selects for these maneuvers.  A short video describing this can be found [here](https://www.youtube.com/watch?v=aHHoGHcgK9k). Basically, if multiple conflicting inputs are pressed, the game decides one of them to override the others.  This can work out in the players favor in certain conditions.  The two option-selects I implement are the crouch-tech and an option-select sweep to catch backdashes (shown in linked video above).  Videos below:

<a href="http://www.youtube.com/watch?feature=player_embedded&v=XuaWWm_tqyo
" target="_blank"><img src="http://img.youtube.com/vi/XuaWWm_tqyo/0.jpg" 
alt="IMAGE ALT TEXT HERE" width="240" height="180" border="10" /></a>
<a href="http://www.youtube.com/watch?feature=player_embedded&v=n4E-OgiGngQ
" target="_blank"><img src="http://img.youtube.com/vi/n4E-OgiGngQ/0.jpg" 
alt="IMAGE ALT TEXT HERE" width="240" height="180" border="10" /></a>

#### Results and Discussion
Obviously this stick with its firmware modifications would not be allowed in competitive play.  However, I found it to be an interesting exercise and demonstration of the arduino's capabilities and the ability to take advantage of the current mechanics in Street Fighter.  Modifications aside, the fightstick functions as a very capable controller with no noticeable input lag.  In fact, in the heat of a match, I found myself forgetting that I was not using my other more professionally made fightstick.  With help from a classmate I found I was able to translate the inputs through the USB HID so that my fightstick was read as a controller on my PS3 and I was able to play normally.

#### Conclusions
Given more time, I would have applied a wood finish to the outer walls of the stick.  I still plan to do this when I have the time.  Additionally, I would like to replace the Arduino entirely with a PS360+ PCB so I can use the fightstick on consoles besides PS3.

#### Special Thanks
I would like to thank Professor Josef Spjut at Harvey Mudd for allowing me to do this project for class as I would not have had the time to do this if it was not school work.

I would also like to thank Tyler Smallwood (Harvey Mudd class of 2017) for his help as a shop proctor and generally getting me started and set up with whatever tools I needed.
