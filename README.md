# A depreciated version of [GIRP](http://www.foddy.net/GIRP.html)

![](https://iheartcats.com/wp-content/uploads/2020/09/15871902_1099453596832566_3557635749273180674_n-e1599916073805.jpg)

> *Edit on 14/3/2023*: I will be archiving this project until I can figure out what game engine I want to write it in. While Raylib is by no means a bad option, I am not technically competent enough to begin writing this in `C`.

[**Rock climbing**](https://images.genius.com/d1cde25d34e647d7ffacefcea11fc287.1000x1000x1.jpg) is one of my core pastimes. So is watching people play [*frustrating games*](https://store.steampowered.com/app/240720/Getting_Over_It_with_Bennett_Foddy/) with unusual mechanics.

As such, after learning about the wonderful [***Raylib***](https://github.com/raysan5/raylib), which both gave me the **cool hackerman edge** of working in an IDE to code most of my game, whilst abstracting away the most **annoying** parts of writing a game engine from scratch in SDL2 and OpenGL, it was simply a matter of time before I attempted a GIRP remake in Raylib. *(It was this or [QWOP](http://www.foddy.net/Athletics.html) man, and that game's kinematics seem even more demonic to work out.)*

However, as I will surely butcher the masterpiece that is the original, I have opted to name my fam remake ***gip*** *(lowercase, minus a letter)*. All i can ask is that the creators of the original masterpiece find it in their heart to forgive me.

---

## The [plan](https://www.tiktok.com/@viralclips2k/video/7113461341448326402?lang=en)

![](https://i.kym-cdn.com/photos/images/original/001/856/682/bfc.jpg)

* compartmentalize each phase and aspect of the game into a different `.c` file to allow for easier refactoring
* user input (keyboard buttons) to be **randomly generated** as rocks that can be gripped onto and inputted when climber's **hand** within a certain radius of the hold
* bird enemy that randomly harasses climber character, providing obstruction from reaching usable hold
* figure out the **math** to simulate body part movement and realistic momentum (connected by joints), with *dangling* and *swinging*
* *timer* and *current climber height count* which acts as the player's score
* *scaling difficulty*, as the climber goes higher, holds are spawned further apart
* some ending *cutscene*/ *prize*

> *Edit on 9/3/2023:* There might be moments of weakness, but I will persevere through writing this in C.

---

## How do I run the game?

Assuming you already have ***[Raylib](https://github.com/raysan5/raylib) with MinGW compiler*** installed to your local machine, simply run the following commands in your desired file directory.

```bash
git clone https://github.com/gongahkia/gip-the-shitty-sequel
cd main-game
cc main.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o "gip-game"
```

If you run `ls` in the current file directory, you should see an executable file titled `gip-game` listed inside. To run the game, simply run the following command.

```bash
./gip-game 
```

---

## I do not have Raylib installed. What do I do?

Follow the installation instructions below depending on your operating system.

### Windows 

1. Install ***Raylib Windows Installer (with MinGW Compiler)*** from Raysan's [itch.io page](https://raysan5.itch.io/raylib).
    * scroll down to the *Downloads* section

2. Follow the instructions provided by the Raylib installer. 

3. Once Raylib has been downloaded *(refer to the filepath `C:\raylib`)*, enter your desired file directory and run the following code.

4. Note that you will **not** be able to run the following commands if Git Bash is not installed on your system. If so, follow the [instructions](https://gitforwindows.org/) to download Git bash.

```bash
git clone https://github.com/gongahkia/gip-the-shitty-sequel
cd main-game
cc main.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o "gip-game"
./gip-game 
```

### Mac and Linux

The following instructions **assume** a Debian-based *distro/ system*, and are taken from Raysan's stellar [Raylib documentation](https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux). Please use the relevant commands depending on your distro.

*an example:*

| Operating System | Terminal commands |
| :---: | :--- |
| Unix-based system *(like MacOS)* | `brew update && brew upgrade && brew autoremove` | 
| Debian-based distro | `sudo apt get update && sudo apt get upgrade && sudo apt get autoremove` | 
| Redhat-based distro *(like Fedora)* | `sudo dnf update && sudo dnf upgrade && sudo dnf autoremove` |

1. If you **do not** have a C and C++ compiler *(such as g++, gcc, Clangd)* installed, run the following command.

```bash
sudo apt install build-essential git
sudo apt install cmake
```

2. Additionally, you will need to run this command to install supporting Raylib libraries.

```bash
sudo apt install libasound2-dev mesa-common-dev libx11-dev libxrandr-dev libxi-dev xorg-dev libgl1-mesa-dev libglu1-mesa-dev
```

3. We will then git clone the relevant Raylib repository into our local folder and build a static version of the Raylib compiler.

```bash
git clone https://github.com/raysan5/raylib.git raylib
cd raylib/src/
make PLATFORM=PLATFORM_DESKTOP
```

4. Lastly, to finalize our installation, run the following command without switching from the previous file directory.

```bash
sudo make install
```

5. Now that Raylib has been installed to your system, we will proceed to *clone the game files* from this Git repository and *build the game* on your local machine, by running the following commands.

```bash
git clone https://github.com/gongahkia/gip-the-shitty-sequel
cd main-game
cc main.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o "gip-game"
```

> Note that for MacOS, the command to compile the game is slightly different. Run the following.
>
> ```bash
> cc main.c `pkg-config --libs --cflags raylib` -o "gip-game"
> ```

6. To run the game, we will run the following command.

```bash
./gip-game
```

---
