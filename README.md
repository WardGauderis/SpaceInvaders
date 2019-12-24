
# Space Qubes
Project Gevorderd Programmeren 2019 - 2020

[![Build Status](https://travis-ci.com/WardGauderis/SpaceInvaders.svg?token=xiF4cJD9dReqnxy3pcqr&branch=master)](https://travis-ci.com/WardGauderis/SpaceInvaders)

Rules:
- The player loses the game when he has no more lives left or when the Qubes reach te bottom of the screen.
- The player wins when he survives all the waves provided in the 'data' folder.
- Try to survive as long as possible!

Controls:
- arrow keys or Q an D (azerty) to move left and right
- space to shoot
- escape to pause
- Enter to play

Customisation:
- All waves are customisable. To add a new wave, add a 'waveX.json' file to 'data/waves'.
- In a wave, you can customise: 
    - the wave title
    - the wave speed
    - the amount of rows
    - the distance between rows
    - the amount of enemies in a row
    - the type of an enemy (different types have different abilities and defaults) (currently existing types are 'default' and 'spy')
    - the shooting cooldown of an enemy
    - the speed of the enemy's bullet
    - the enemy's horizontal speed
    - the enemy's dimensions
    - the amount of lives of an enemy
    - the amount of points the player gets for killing the enemy
- None of the customizable values are required except for 'rows' and have defaults.
- All of the numerical values in the json file are interpreted as floats that are multipliers to the default values.
- See some files in 'data/waves' for examples.

Used assets:
- The Cannery Kevin MacLeod (incompetech.com) - Licensed under Creative Commons: By Attribution 3.0
- TF2 Build font (https://www.dafont.com/tf2-build.fontq) - Free for personal use only
- TF2 Secondary font (https://www.dafont.com/tf2-secondary.font) - Free for personal use only
