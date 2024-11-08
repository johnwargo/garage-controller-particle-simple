# Garage Controller Particle Simple

This repository contains the Arduino sketch for a simple garage door opener based on the [Particle Photon](https://store.particle.io/products/photon-2) platform. I built this years ago when I first discovered the Particle Platform and a version of this software has been running on a Particle device in my garage ever since.

The project is really simple, it defines a single function `pushButton` that, when executed, turns a relay on for a half of a second (500ms) then turns it off.

```c
int pushButton(String param){
    // Turn the relay on 
    digitalWrite(relayPin, HIGH);
    // Wait half a second
    delay(500);
    // Turn the relay off
    digitalWrite(relayPin, LOW);  
    // must return something, so return a zero (-1 means failure)
    return 0;
}
```

The relay connects across the two wires that you'll find connected between the opener button and the garage door opener. When the relay shorts the wires (by turning the relay on) it looks to the garage door opener like you pushed the button and the garage door opener triggers (up or down depending on where it is at that time). 

**Note:** Most modern garage door openers use a wireless connection between the remote button and the garage door opener, so this will only work on ones that actually have wires.

My favorite part of the Particle platform is the cloud service that comes with it. Remember that function I described earlier? Well, through the Particle platform you can remotely trigger that function's execution through an API call to the Particle Platform or even by triggering the function from directly within the Particle Platform portal.

Here's the code that registers the local function in the Particle cloud for remote execution

```c
//======================================================
// Define the external function call to push the button
//======================================================
Particle.function("pushButton", pushButton);
```

## Opening the Garage Door

What I did for my implementation was build a native application in [Java (for Android)](https://github.com/johnwargo/particle-garage-controller-app-android) that allowed me to open and close the garage door from my phone. Since I wanted this to work on Android and iOS, I built an [Ionic](https://ionicframework.com/) app for it. My most recent iteration is a Flutter application that I've not yet published the source code for.

## Implementation Advice

Even though the sketch herein has a `.ino` extension, don't open it in the Arduino IDE; use the IDE built into the Particle Platform. The cloud IDE allows you to build and deploy over the network.

---

You can find information on many different topics on my [personal blog](http://www.johnwargo.com). Learn about all of my publications at [John Wargo Books](http://www.johnwargobooks.com).

If you find this code useful and feel like thanking me for providing it, please consider <a href="https://www.buymeacoffee.com/johnwargo" target="_blank">Buying Me a Coffee</a>, or making a purchase from [my Amazon Wish List](https://amzn.com/w/1WI6AAUKPT5P9).
 