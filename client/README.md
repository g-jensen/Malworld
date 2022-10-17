# Malworld

## TODO
- Basic engine features
  1. Map management (import, creation, and export)
  2. Sound management (events?)
  3. System to determine which Drawables are visible and add them to list
- Gameplay features
  1. NPC Dialogue

## Links
[UML Tree Link](https://lucid.app/lucidchart/a2a08f0b-dfa6-4641-a8cc-3fd7d605779a/edit?viewport_loc=-332%2C-309%2C3678%2C1806%2C0_0&invitationId=inv_33b1dea5-221b-4891-8058-8ce4be728af2#)

[Taiga Link](https://tree.taiga.io/project/lackability-malworld-1/kanban)

[Raycasting Link](https://lodev.org/cgtutor/raycasting.html#The_Basic_Idea_)

## Merging Guidelines
- Create new branch with your edit and make a pull request

## Code Style Guidelines
- Include order
  1. C/C++ Libraries
  2. Third-party libraries (SFML)
  3. Local files
- Naming
  - Functions and variables would be like_this (all lowercase with underscores)
  - Class names should be LikeThis (no underscores)
- Header files should be .hpp (not .h)
- Put  `#pragma once` at the beginning of header files
- If unsure about something, look at similar examples in already existing code
