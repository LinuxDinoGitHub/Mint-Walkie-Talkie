# Mint-Walkie-Talkie
An ATMega328P-powered compact walkie-talkie PCB that fits inside a mint can. Uses the NRF24L01+PA+LNA module to communicate using a custom protocol on a PCB. Range of around 1km.
<img width="1920" height="1080" alt="Mint3" src="https://github.com/user-attachments/assets/9ce9aa41-7450-46cb-8793-679e28c6e5ae" />
<img width="1920" height="1080" alt="Mint1" src="https://github.com/user-attachments/assets/97eda929-5bc5-458e-8555-3c8a0d9b01d2" />

## About this project
I've been thinking to make a walkie talkie since the first time I was introduced to PCB design. I have been trying since with the PCB e-ink card project, but that was a side project I never finished (maybe one day). A lot of movies show that walkie-talkies can shrink to absurdly small sizes, which I believe it can with the correct ICs and good PCB layout. But this is my first attempt at making a compact walkie-talkie module with the NRF24L01 module and ATMega328p MCU. The NRF24L01 is known for its long range, around 1km, and it is very compatible and beginner-friendly for hobbyists to use.

### Why did I make this project?
Following my last radio project, I realised I needed some walkie-talkies to match it, so I decided to make this. It is also a test of the world of electronics and how small one can make a walkie-talkie (for now, not so small yet).

### How do you use it?
Simply hold the button on the PCB/mint can, and you'll go into "transmit" mode. Release and it will go into "receive". It is essentially a half-duplex walkie-talkie. 

**Option A: Mint box outer shell**

You should have one of your own mint boxes like the following:
<img width="1200" height="1200" alt="image" src="https://github.com/user-attachments/assets/4a19bac4-6b34-4972-beb3-8b3ad18727cc" />

You will need to use a hammer & nail to cut out the holes for the speakers by using a nail to trace the outline, then cutting it out. **Tip: use the [stencil provided here](https://github.com/LinuxDinoGitHub/Mint-Walkie-Talkie/blob/main/assets/Stencil_print_in_a4.pdf) to print out and mark the traces.** More photos coming soon.

**Dimensions:**

<img width="907" height="480" alt="image" src="https://github.com/user-attachments/assets/ad7ad900-9e05-4b46-a0d8-2eae7acbafc5" />
<img width="753" height="397" alt="image" src="https://github.com/user-attachments/assets/aa5d8654-96f3-4468-98b4-8c1e9af48746" />

A: 8.5mm

B: 10mm

C: 20mm

D: 3.5mm

The PTT button will need to be 3D printed ([file here](https://github.com/LinuxDinoGitHub/Mint-Walkie-Talkie/blob/main/models/button.step)) and assembled by press-fitting from the bottom (use glue to help if you punched your hole too big) to the 6mm button on the PCB trace through the mint box, using the taper to lock it in place.

<img width="417" height="563" alt="image" src="https://github.com/user-attachments/assets/e0bf6ed1-586d-4a27-bf0c-82e476e3ef2f" />


**Option B: 3D printed replica mint box casing ([Link here](https://github.com/LinuxDinoGitHub/Mint-Walkie-Talkie/blob/main/models/3D_printed_case.step))**

If you don't have a mint box, you can use a 3D printed case and save yourself the hassle of manually making the holes. Print the file linked above; the button is included, assembly same as above.

## Key features
- PPT Button, half-duplex system as mentioned above
- LED signifier
- Can fit into a mint can
- Powered by a 3.7 V LiPo battery with a rechargeable battery protection module (TP4056)
- 8Ohm 1W Speaker amplified with PAM8403
- Microphone input with MAX9814

## [Schematic](https://github.com/LinuxDinoGitHub/Mint-Walkie-Talkie/tree/main/pcb)
<img width="1133" height="830" alt="image" src="https://github.com/user-attachments/assets/be77f6fe-ac40-4199-ad9d-9144c22e6482" />

## [PCB](https://github.com/LinuxDinoGitHub/Mint-Walkie-Talkie/tree/main/pcb)

Simple 3-layer PCB, with a ground plane for removing noise.

<img width="486" height="783" alt="image" src="https://github.com/user-attachments/assets/c4643ca3-5fc9-4ff5-a01a-375ff76a58bf" />

### First layer

<img width="512" height="786" alt="image" src="https://github.com/user-attachments/assets/37a67e19-c5cd-4419-bc74-5ec03042ecb0" />

### Second layer (Ground plane)

<img width="504" height="785" alt="image" src="https://github.com/user-attachments/assets/21f63559-4a9c-4c0a-b0c1-abae1db3ea65" />

### Third layer

<img width="483" height="782" alt="image" src="https://github.com/user-attachments/assets/2e5c425d-ea60-4939-893b-b69a835dfe4c" />

## 3D View

### Front
<img width="1008" height="718" alt="image" src="https://github.com/user-attachments/assets/c23c265b-5587-4853-b0cf-9a890219c132" />

### Back
<img width="875" height="550" alt="image" src="https://github.com/user-attachments/assets/235e5a36-0063-4a68-822a-9816af356198" />

## Example use case in Mint can
<img width="1920" height="1080" alt="Mint3" src="https://github.com/user-attachments/assets/f4cfc4dc-94a4-49d8-a74e-014f9e0a8241" />

## [Firmware](https://github.com/LinuxDinoGitHub/Mint-Walkie-Talkie/blob/main/firmware/mint.ino)
The firmware requires another Arduino (Uno, Mega, Nano, etc.) to program the ATMega328P. This is done with the 6 pins on the PCB (see below); for more details, check out this [Arduino article on how to program an ATMega328P](https://docs.arduino.cc/built-in-examples/arduino-isp/ArduinoToBreadboard/). All the pins you need are provided in the header pins.
<img width="851" height="569" alt="image" src="https://github.com/user-attachments/assets/f3121d8b-0e21-4f76-9268-8b6e19f1280a" />
<img width="240" height="613" alt="image" src="https://github.com/user-attachments/assets/0a1812a5-c75d-4c35-b186-a82165ac7d3a" />

## BOM
[BOM](https://github.com/LinuxDinoGitHub/Mint-Walkie-Talkie/blob/main/BOM_with_links.csv)** with links **to vendors and sources of material.
[BOM](https://github.com/LinuxDinoGitHub/Mint-Walkie-Talkie/blob/main/BOM_KiCAD_generated.csv) generated by KiCAD with components listing.
The project will cost an average of $6 per walkie-talkie, but most of the materials require bulk purchases.

## Zine page
[<img width="669" height="1024" alt="1779976642758-aed0d11d-6999-48d8-a8b2-eb19d6b463cd_1" src="https://github.com/user-attachments/assets/5d44b8b9-f760-4881-96fc-887b8b9c17dc" />](https://github.com/LinuxDinoGitHub/Mint-Walkie-Talkie/blob/main/Mint_zine_final.pdf)

## Credits
Thank you to the great documentation from [RF24 library](https://github.com/nRF24/RF24), a really convenient and high-speed data transfer library for the NRF24L01.
