# MAX6956
Extremely basic Arduino sketch for displaying 4 digits on 4 7-seg displays using two MAX6956s. Includes function outputDigit that takes in a 4-digit number in the form of a string and outputs that number to the 4 7-segs. Ports 22-29 and 14-21 on each MAX6956s are used for the 7-segs. Global segment brightness can be set in constructor and ranges from 0x00 to 0xFF.
