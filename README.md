# CGC Challenges

There are a couple other repos for the CGC binaries, notably the venerable
[cb-multios](https://github.com/trailofbits/cb-multios) from Trail of Bits (which this
is based on).

They all have weird build system hacks going on that make it pretty hard to tune your
build. This one doesn't!

The CGC challenge set is intended to facilitate testing fuzzers, symbolic execution
engines, and other binary analysis tools on a robust and realistic test set. It is
recommended by [Klees et. al](https://arxiv.org/pdf/1808.09700.pdf) and most other
Fuzzing evaluation papers, alongside the
[LAVA-M](https://sites.google.com/site/steelix2017/home/lava) dataset from Gavitt et. al.

This repository will build all CGC binaries and generate the "polls" for them, which
are essentially input seeds.

## Build Instructions

### Install Dependencies

```sh
$ sudo apt-get install meson ninja-build build-essential
```

### Compile Challenges

```sh
$ meson builddir
$ meson compile -C builddir
```

### "Install" Challenges

By default, challenges will be "installed" to `./output/`.

```sh
$ meson install -C builddir
```

## Change Output Directory

You can specify a custom install directory with:

`meson "-Dinstall_path=/path/to/install/dir" builddir`

## Customizing Build

Because this repository uses `meson` as a build system, you can customize the build
easily:

- Custom `CFLAGS` example: `meson -Dc_args='-fno-pie -no-pie'`
- Custom `LDFLAGS` example: `meson -Dc_link_args='-fuse-ld=mold`

## Do NOT Build Polls

Poll building can be disabled entirely with `meson -Dno_polls=true`

## Automatic Python2 Module Installs

Four Python2 modules are required to build this project's polls (which are basically
just input seeds):

* `pycryptodome`
* `pyyaml`
* `matplotlib`

These will *NOT* be installed automatically by default, but if you are missing these
modules *or* missing Python2 pip, the build system can install them for you and set
up Python2. Just pass `-Dinstall_pip_modules`.

## Enabling and Disabling Challenges

By default all working challenges are enabled and will be built. The build is reasonably fast, but you may for some reason want to disable challenges.

### Disable Challenges

You can specify a list of challenges to disable with:

`meson "-Ddisable=['TFTTP', 'virtual_pet']" builddir`

All challenges are enabled by default, so adding a challenge to the list of disabled
challenges will toggle it off. The list of disabled challenges defaults to the list of
broken challenges, but if this option is passed the passed list will *not* override the
list of broken challenges unless `"-Denable_broken"` is also passed.

### Enable Challenges

You can specify a list of challenges to enable with:

`meson "-Denable=['TFTTP', 'virtual_pet']" builddir`

*Only* challenges that are explicitly enabled will be built if this option is provided.

### Enable Broken Challenges

You can enable broken challenges (for testing purposes if you are trying to fix one, in
which case, thanks!) with:

`meson "-Denable_broken" builddir` 

## Challenge Status

Not all challenges are working yet. Generally, multi-binary challenges are not set
up, and some of the challenges have issues with improper header files. Some of these
are easy fixes and will be fixed soon by me (or you can PR a fix 🥰). Some are harder.

_Working_: *186*

_Not working_: *53*

Legend:

✅: The challenge compiles!
❌: The challenge does not compile :(
| Challenge                                                                                                                     | Codename    | Building | Polls Generated |
| ----------------------------------------------------------------------------------------------------------------------------- | ----------- | -------- | --------------- |
| [0maker](challenges/0maker/README.md)                                                                                         | NRFIN_00014 | ❌        | ❌               |
| [3D_Image_Toolkit](challenges/3D_Image_Toolkit/README.md)                                                                     | CROMU_00001 | ✅        | ❌               |
| [AIS-Lite](challenges/AIS-Lite/README.md)                                                                                     | CROMU_00004 | ✅        | ✅               |
| [ASCII_Content_Server](challenges/ASCII_Content_Server/README.md)                                                             | CROMU_00006 | ✅        | ✅               |
| [ASL6parse](challenges/ASL6parse/README.md)                                                                                   | CROMU_00008 | ✅        | ✅               |
| [A_Game_of_Chance](challenges/A_Game_of_Chance/README.md)                                                                     | CROMU_00003 | ❌        | ❌               |
| [Accel](challenges/Accel/README.md)                                                                                           | CROMU_00002 | ❌        | ❌               |
| [Audio_Visualizer](challenges/Audio_Visualizer/README.md)                                                                     | CROMU_00009 | ✅        | ✅               |
| [Azurad](challenges/Azurad/README.md)                                                                                         | CROMU_00010 | ✅        | ❌               |
| [BIRC](challenges/BIRC/README.md)                                                                                             | CROMU_00015 | ❌        | ❌               |
| [Barcoder](challenges/Barcoder/README.md)                                                                                     | CROMU_00011 | ✅        | ✅               |
| [BitBlaster](challenges/BitBlaster/README.md)                                                                                 | CROMU_00016 | ✅        | ✅               |
| [Bloomy_Sunday](challenges/Bloomy_Sunday/README.md)                                                                           | CROMU_00017 | ✅        | ✅               |
| [Blubber](challenges/Blubber/README.md)                                                                                       | Unknown     | ❌        | ❌               |
| [Board_Game](challenges/Board_Game/README.md)                                                                                 | CROMU_00018 | ✅        | ✅               |
| [BudgIT](challenges/BudgIT/README.md)                                                                                         | CROMU_00019 | ✅        | ✅               |
| [CGC_Board](challenges/CGC_Board/README.md)                                                                                   | CROMU_00024 | ❌        | ❌               |
| [CGC_File_System](challenges/CGC_File_System/README.md)                                                                       | CROMU_00025 | ✅        | ❌               |
| [CGC_Hangman_Game](challenges/CGC_Hangman_Game/README.md)                                                                     | CROMU_00026 | ✅        | ✅               |
| [CGC_Image_Parser](challenges/CGC_Image_Parser/README.md)                                                                     | CROMU_00027 | ❌        | ❌               |
| [CGC_Planet_Markup_Language_Parser](challenges/CGC_Planet_Markup_Language_Parser/README.md)                                   | CROMU_00028 | ✅        | ❌               |
| [CGC_Symbol_Viewer_CSV](challenges/CGC_Symbol_Viewer_CSV/README.md)                                                           | CROMU_00029 | ✅        | ✅               |
| [CGC_Video_Format_Parser_and_Viewer](challenges/CGC_Video_Format_Parser_and_Viewer/README.md)                                 | CROMU_00030 | ✅        | ❌               |
| [CLOUDCOMPUTE](challenges/CLOUDCOMPUTE/README.md)                                                                             | CROMU_00035 | ❌        | ❌               |
| [CML](challenges/CML/README.md)                                                                                               | Unknown     | ❌        | ❌               |
| [CNMP](challenges/CNMP/README.md)                                                                                             | CROMU_00036 | ✅        | ✅               |
| [COLLIDEOSCOPE](challenges/COLLIDEOSCOPE/README.md)                                                                           | CROMU_00037 | ✅        | ✅               |
| [CTTP](challenges/CTTP/README.md)                                                                                             | CROMU_00041 | ✅        | ✅               |
| [CableGrind](challenges/CableGrind/README.md)                                                                                 | CROMU_00020 | ✅        | ✅               |
| [CableGrindLlama](challenges/CableGrindLlama/README.md)                                                                       | CROMU_00021 | ✅        | ✅               |
| [Carbonate](challenges/Carbonate/README.md)                                                                                   | Unknown     | ❌        | ❌               |
| [Casino_Games](challenges/Casino_Games/README.md)                                                                             | CROMU_00022 | ✅        | ✅               |
| [Cereal_Mixup__A_Cereal_Vending_Machine_Controller](challenges/Cereal_Mixup__A_Cereal_Vending_Machine_Controller/README.md)   | CROMU_00023 | ✅        | ✅               |
| [Character_Statistics](challenges/Character_Statistics/README.md)                                                             | CROMU_00031 | ✅        | ✅               |
| [Charter](challenges/Charter/README.md)                                                                                       | Unknown     | ❌        | ❌               |
| [Checkmate](challenges/Checkmate/README.md)                                                                                   | CROMU_00032 | ✅        | ✅               |
| [Childs_Game](challenges/Childs_Game/README.md)                                                                               | CROMU_00034 | ✅        | ✅               |
| [Corinth](challenges/Corinth/README.md)                                                                                       | Unknown     | ❌        | ❌               |
| [Cromulence_All_Service](challenges/Cromulence_All_Service/README.md)                                                         | CROMU_00040 | ✅        | ✅               |
| [DFARS_Sample_Service](challenges/DFARS_Sample_Service/README.md)                                                             | CROMU_00043 | ✅        | ✅               |
| [Diary_Parser](challenges/Diary_Parser/README.md)                                                                             | CROMU_00044 | ✅        | ✅               |
| [Differ](challenges/Differ/README.md)                                                                                         | KPRCA_00002 | ✅        | ✅               |
| [Diophantine_Password_Wallet](challenges/Diophantine_Password_Wallet/README.md)                                               | KPRCA_00007 | ✅        | ✅               |
| [Dive_Logger](challenges/Dive_Logger/README.md)                                                                               | KPRCA_00008 | ✅        | ✅               |
| [Divelogger2](challenges/Divelogger2/README.md)                                                                               | KPRCA_00009 | ✅        | ✅               |
| [Document_Rendering_Engine](challenges/Document_Rendering_Engine/README.md)                                                   | KPRCA_00010 | ✅        | ✅               |
| [Dungeon_Master](challenges/Dungeon_Master/README.md)                                                                         | KPRCA_00011 | ❌        | ❌               |
| [ECM_TCM_Simulator](challenges/ECM_TCM_Simulator/README.md)                                                                   | KPRCA_00012 | ✅        | ✅               |
| [Eddy](challenges/Eddy/README.md)                                                                                             | KPRCA_00013 | ✅        | ✅               |
| [Email_System_2](challenges/Email_System_2/README.md)                                                                         | KPRCA_00016 | ✅        | ✅               |
| [Enslavednode_chat](challenges/Enslavednode_chat/README.md)                                                                   | KPRCA_00017 | ❌        | ❌               |
| [Estadio](challenges/Estadio/README.md)                                                                                       | KPRCA_00018 | ✅        | ❌               |
| [EternalPass](challenges/EternalPass/README.md)                                                                               | KPRCA_00019 | ❌        | ❌               |
| [FASTLANE](challenges/FASTLANE/README.md)                                                                                     | KPRCA_00023 | ❌        | ❌               |
| [FISHYXML](challenges/FISHYXML/README.md)                                                                                     | KPRCA_00027 | ✅        | ✅               |
| [FSK_BBS](challenges/FSK_BBS/README.md)                                                                                       | KPRCA_00031 | ✅        | ✅               |
| [FSK_Messaging_Service](challenges/FSK_Messaging_Service/README.md)                                                           | KPRCA_00032 | ✅        | ✅               |
| [FUN](challenges/FUN/README.md)                                                                                               | KPRCA_00033 | ❌        | ❌               |
| [FablesReport](challenges/FablesReport/README.md)                                                                             | KPRCA_00020 | ✅        | ✅               |
| [FaceMag](challenges/FaceMag/README.md)                                                                                       | Unknown     | ❌        | ❌               |
| [Facilities_Access_Control_System](challenges/Facilities_Access_Control_System/README.md)                                     | KPRCA_00021 | ✅        | ✅               |
| [FailAV](challenges/FailAV/README.md)                                                                                         | KPRCA_00022 | ✅        | ✅               |
| [FileSys](challenges/FileSys/README.md)                                                                                       | KPRCA_00024 | ✅        | ✅               |
| [Filesystem_Command_Shell](challenges/Filesystem_Command_Shell/README.md)                                                     | KPRCA_00025 | ✅        | ✅               |
| [Finicky_File_Folder](challenges/Finicky_File_Folder/README.md)                                                               | KPRCA_00026 | ✅        | ✅               |
| [Flash_File_System](challenges/Flash_File_System/README.md)                                                                   | KPRCA_00028 | ✅        | ✅               |
| [Flight_Routes](challenges/Flight_Routes/README.md)                                                                           | KPRCA_00029 | ✅        | ✅               |
| [Fortress](challenges/Fortress/README.md)                                                                                     | KPRCA_00030 | ✅        | ✅               |
| [GPS_Tracker](challenges/GPS_Tracker/README.md)                                                                               | KPRCA_00036 | ✅        | ✅               |
| [GREYMATTER](challenges/GREYMATTER/README.md)                                                                                 | KPRCA_00039 | ✅        | ✅               |
| [Game_Night](challenges/Game_Night/README.md)                                                                                 | KPRCA_00034 | ✅        | ✅               |
| [Glue](challenges/Glue/README.md)                                                                                             | KPRCA_00035 | ✅        | ✅               |
| [GreatView](challenges/GreatView/README.md)                                                                                   | KPRCA_00037 | ✅        | ✅               |
| [Gridder](challenges/Gridder/README.md)                                                                                       | KPRCA_00040 | ✅        | ✅               |
| [Griswold](challenges/Griswold/README.md)                                                                                     | KPRCA_00041 | ❌        | ❌               |
| [Grit](challenges/Grit/README.md)                                                                                             | KPRCA_00042 | ✅        | ✅               |
| [H20FlowInc](challenges/H20FlowInc/README.md)                                                                                 | KPRCA_00043 | ✅        | ✅               |
| [HIGHCOO](challenges/HIGHCOO/README.md)                                                                                       | KPRCA_00048 | ✅        | ✅               |
| [HackMan](challenges/HackMan/README.md)                                                                                       | KPRCA_00044 | ✅        | ✅               |
| [Headscratch](challenges/Headscratch/README.md)                                                                               | KPRCA_00046 | ✅        | ✅               |
| [HeartThrob](challenges/HeartThrob/README.md)                                                                                 | KPRCA_00047 | ✅        | ✅               |
| [HighFrequencyTradingAlgo](challenges/HighFrequencyTradingAlgo/README.md)                                                     | KPRCA_00049 | ✅        | ✅               |
| [Hug_Game](challenges/Hug_Game/README.md)                                                                                     | KPRCA_00050 | ✅        | ✅               |
| [INSULATR](challenges/INSULATR/README.md)                                                                                     | KPRCA_00053 | ✅        | ✅               |
| [Image_Compressor](challenges/Image_Compressor/README.md)                                                                     | KPRCA_00052 | ✅        | ❌               |
| [KKVS](challenges/KKVS/README.md)                                                                                             | NRFIN_00004 | ❌        | ❌               |
| [KTY_Pretty_Printer](challenges/KTY_Pretty_Printer/README.md)                                                                 | NRFIN_00005 | ✅        | ✅               |
| [Kaprica_Go](challenges/Kaprica_Go/README.md)                                                                                 | KPRCA_00054 | ✅        | ❌               |
| [Kaprica_Script_Interpreter](challenges/Kaprica_Script_Interpreter/README.md)                                                 | NRFIN_00001 | ❌        | ❌               |
| [LAN_Simulator](challenges/LAN_Simulator/README.md)                                                                           | NRFIN_00006 | ❌        | ❌               |
| [LMS](challenges/LMS/README.md)                                                                                               | NRFIN_00009 | ✅        | ✅               |
| [LazyCalc](challenges/LazyCalc/README.md)                                                                                     | NRFIN_00008 | ✅        | ✅               |
| [Lazybox](challenges/Lazybox/README.md)                                                                                       | NRFIN_00007 | ❌        | ❌               |
| [Loud_Square_Instant_Messaging_Protocol_LSIMP](challenges/Loud_Square_Instant_Messaging_Protocol_LSIMP/README.md)             | NRFIN_00011 | ✅        | ✅               |
| [LulzChat](challenges/LulzChat/README.md)                                                                                     | NRFIN_00012 | ❌        | ❌               |
| [Material_Temperature_Simulation](challenges/Material_Temperature_Simulation/README.md)                                       | NRFIN_00015 | ✅        | ❌               |
| [Mathematical_Solver](challenges/Mathematical_Solver/README.md)                                                               | NRFIN_00016 | ✅        | ✅               |
| [Matrix_Math_Calculator](challenges/Matrix_Math_Calculator/README.md)                                                         | NRFIN_00018 | ✅        | ✅               |
| [Message_Service](challenges/Message_Service/README.md)                                                                       | NRFIN_00019 | ✅        | ❌               |
| [Messaging](challenges/Messaging/README.md)                                                                                   | NRFIN_00020 | ❌        | ❌               |
| [Mixology](challenges/Mixology/README.md)                                                                                     | Unknown     | ❌        | ❌               |
| [Modern_Family_Tree](challenges/Modern_Family_Tree/README.md)                                                                 | NRFIN_00023 | ✅        | ✅               |
| [Monster_Game](challenges/Monster_Game/README.md)                                                                             | NRFIN_00024 | ✅        | ✅               |
| [Mount_Filemore](challenges/Mount_Filemore/README.md)                                                                         | NRFIN_00025 | ✅        | ✅               |
| [Movie_Rental_Service](challenges/Movie_Rental_Service/README.md)                                                             | NRFIN_00026 | ✅        | ✅               |
| [Movie_Rental_Service_Redux](challenges/Movie_Rental_Service_Redux/README.md)                                                 | NRFIN_00027 | ✅        | ✅               |
| [Multi_Arena_Pursuit_Simulator](challenges/Multi_Arena_Pursuit_Simulator/README.md)                                           | NRFIN_00029 | ✅        | ✅               |
| [Multi_User_Calendar](challenges/Multi_User_Calendar/README.md)                                                               | NRFIN_00035 | ✅        | ✅               |
| [Multicast_Chat_Server](challenges/Multicast_Chat_Server/README.md)                                                           | NRFIN_00030 | ❌        | ❌               |
| [Multipass](challenges/Multipass/README.md)                                                                                   | NRFIN_00032 | ❌        | ❌               |
| [Multipass2](challenges/Multipass2/README.md)                                                                                 | NRFIN_00033 | ❌        | ❌               |
| [Multipass3](challenges/Multipass3/README.md)                                                                                 | NRFIN_00034 | ❌        | ❌               |
| [Music_Store_Client](challenges/Music_Store_Client/README.md)                                                                 | NRFIN_00036 | ✅        | ✅               |
| [NarfAgainShell](challenges/NarfAgainShell/README.md)                                                                         | NRFIN_00037 | ✅        | ✅               |
| [NarfRPN](challenges/NarfRPN/README.md)                                                                                       | NRFIN_00038 | ✅        | ✅               |
| [Network_File_System](challenges/Network_File_System/README.md)                                                               | NRFIN_00040 | ✅        | ❌               |
| [Network_File_System_v3](challenges/Network_File_System_v3/README.md)                                                         | NRFIN_00041 | ✅        | ✅               |
| [Network_Queuing_Simulator](challenges/Network_Queuing_Simulator/README.md)                                                   | NRFIN_00042 | ✅        | ❌               |
| [Neural_House](challenges/Neural_House/README.md)                                                                             | YAN01_00007 | ✅        | ✅               |
| [NoHiC](challenges/NoHiC/README.md)                                                                                           | YAN01_00009 | ❌        | ❌               |
| [No_Paper._Not_Ever._NOPE](challenges/No_Paper._Not_Ever._NOPE/README.md)                                                     | YAN01_00010 | ✅        | ✅               |
| [OTPSim](challenges/OTPSim/README.md)                                                                                         | Unknown     | ✅        | ✅               |
| [OUTLAW](challenges/OUTLAW/README.md)                                                                                         | Unknown     | ❌        | ❌               |
| [On_Sale](challenges/On_Sale/README.md)                                                                                       | Unknown     | ❌        | ❌               |
| [One_Amp](challenges/One_Amp/README.md)                                                                                       | YAN01_00011 | ✅        | ✅               |
| [One_Vote](challenges/One_Vote/README.md)                                                                                     | YAN01_00012 | ✅        | ✅               |
| [Order_Up](challenges/Order_Up/README.md)                                                                                     | Unknown     | ❌        | ❌               |
| [Overflow_Parking](challenges/Overflow_Parking/README.md)                                                                     | Unknown     | ✅        | ✅               |
| [PCM_Message_decoder](challenges/PCM_Message_decoder/README.md)                                                               | Unknown     | ✅        | ✅               |
| [PKK_Steganography](challenges/PKK_Steganography/README.md)                                                                   | Unknown     | ✅        | ✅               |
| [PRU](challenges/PRU/README.md)                                                                                               | Unknown     | ✅        | ✅               |
| [PTaaS](challenges/PTaaS/README.md)                                                                                           | Unknown     | ✅        | ❌               |
| [Pac_for_Edges](challenges/Pac_for_Edges/README.md)                                                                           | Unknown     | ✅        | ✅               |
| [Packet_Analyzer](challenges/Packet_Analyzer/README.md)                                                                       | Unknown     | ✅        | ✅               |
| [Packet_Receiver](challenges/Packet_Receiver/README.md)                                                                       | Unknown     | ✅        | ✅               |
| [Palindrome](challenges/Palindrome/README.md)                                                                                 | Unknown     | ✅        | ✅               |
| [Palindrome2](challenges/Palindrome2/README.md)                                                                               | Unknown     | ✅        | ✅               |
| [Parking_Permit_Management_System_PPMS](challenges/Parking_Permit_Management_System_PPMS/README.md)                           | Unknown     | ✅        | ✅               |
| [Particle_Simulator](challenges/Particle_Simulator/README.md)                                                                 | Unknown     | ✅        | ❌               |
| [Pattern_Finder](challenges/Pattern_Finder/README.md)                                                                         | Unknown     | ✅        | ✅               |
| [Personal_Fitness_Manager](challenges/Personal_Fitness_Manager/README.md)                                                     | Unknown     | ✅        | ✅               |
| [Pipelined](challenges/Pipelined/README.md)                                                                                   | Unknown     | ❌        | ❌               |
| [Printer](challenges/Printer/README.md)                                                                                       | Unknown     | ✅        | ✅               |
| [QUIETSQUARE](challenges/QUIETSQUARE/README.md)                                                                               | Unknown     | ✅        | ✅               |
| [QuadtreeConways](challenges/QuadtreeConways/README.md)                                                                       | Unknown     | ✅        | ✅               |
| [Query_Calculator](challenges/Query_Calculator/README.md)                                                                     | Unknown     | ❌        | ❌               |
| [RAM_based_filesystem](challenges/RAM_based_filesystem/README.md)                                                             | Unknown     | ❌        | ❌               |
| [REDPILL](challenges/REDPILL/README.md)                                                                                       | Unknown     | ❌        | ❌               |
| [REMATCH_1--Hat_Trick--Morris_Worm](challenges/REMATCH_1--Hat_Trick--Morris_Worm/README.md)                                   | Unknown     | ❌        | ❌               |
| [REMATCH_2--Mail_Server--Crackaddr](challenges/REMATCH_2--Mail_Server--Crackaddr/README.md)                                   | Unknown     | ✅        | ❌               |
| [REMATCH_3--Address_Resolution_Service--SQL_Slammer](challenges/REMATCH_3--Address_Resolution_Service--SQL_Slammer/README.md) | Unknown     | ✅        | ✅               |
| [REMATCH_4--CGCRPC_Server--MS08-067](challenges/REMATCH_4--CGCRPC_Server--MS08-067/README.md)                                 | Unknown     | ❌        | ❌               |
| [REMATCH_5--File_Explorer--LNK_Bug](challenges/REMATCH_5--File_Explorer--LNK_Bug/README.md)                                   | Unknown     | ✅        | ✅               |
| [REMATCH_6--Secure_Server--Heartbleed](challenges/REMATCH_6--Secure_Server--Heartbleed/README.md)                             | Unknown     | ✅        | ✅               |
| [RRPN](challenges/RRPN/README.md)                                                                                             | Unknown     | ✅        | ❌               |
| [Recipe_Database](challenges/Recipe_Database/README.md)                                                                       | Unknown     | ✅        | ✅               |
| [Recipe_and_Pantry_Manager](challenges/Recipe_and_Pantry_Manager/README.md)                                                   | Unknown     | ✅        | ❌               |
| [Rejistar](challenges/Rejistar/README.md)                                                                                     | Unknown     | ❌        | ❌               |
| [Resort_Modeller](challenges/Resort_Modeller/README.md)                                                                       | Unknown     | ✅        | ✅               |
| [SAuth](challenges/SAuth/README.md)                                                                                           | Unknown     | ✅        | ✅               |
| [SCUBA_Dive_Logging](challenges/SCUBA_Dive_Logging/README.md)                                                                 | Unknown     | ✅        | ✅               |
| [SFTSCBSISS](challenges/SFTSCBSISS/README.md)                                                                                 | Unknown     | ✅        | ✅               |
| [SIGSEGV](challenges/SIGSEGV/README.md)                                                                                       | Unknown     | ✅        | ✅               |
| [SLUR_reference_implementation](challenges/SLUR_reference_implementation/README.md)                                           | Unknown     | ✅        | ✅               |
| [SOLFEDGE](challenges/SOLFEDGE/README.md)                                                                                     | Unknown     | ✅        | ✅               |
| [SPIFFS](challenges/SPIFFS/README.md)                                                                                         | Unknown     | ✅        | ✅               |
| [Sad_Face_Template_Engine_SFTE](challenges/Sad_Face_Template_Engine_SFTE/README.md)                                           | Unknown     | ✅        | ✅               |
| [Sample_Shipgame](challenges/Sample_Shipgame/README.md)                                                                       | Unknown     | ✅        | ✅               |
| [Scrum_Database](challenges/Scrum_Database/README.md)                                                                         | Unknown     | ✅        | ✅               |
| [Secure_Compression](challenges/Secure_Compression/README.md)                                                                 | Unknown     | ✅        | ✅               |
| [Sensr](challenges/Sensr/README.md)                                                                                           | Unknown     | ✅        | ✅               |
| [Shipgame](challenges/Shipgame/README.md)                                                                                     | Unknown     | ❌        | ❌               |
| [Shortest_Path_Tree_Calculator](challenges/Shortest_Path_Tree_Calculator/README.md)                                           | Unknown     | ✅        | ✅               |
| [ShoutCTF](challenges/ShoutCTF/README.md)                                                                                     | Unknown     | ✅        | ✅               |
| [Simple_Stack_Machine](challenges/Simple_Stack_Machine/README.md)                                                             | Unknown     | ✅        | ✅               |
| [Single-Sign-On](challenges/Single-Sign-On/README.md)                                                                         | Unknown     | ❌        | ❌               |
| [Snail_Mail](challenges/Snail_Mail/README.md)                                                                                 | Unknown     | ✅        | ✅               |
| [Sorter](challenges/Sorter/README.md)                                                                                         | Unknown     | ✅        | ✅               |
| [Space_Attackers](challenges/Space_Attackers/README.md)                                                                       | Unknown     | ✅        | ✅               |
| [Square_Rabbit](challenges/Square_Rabbit/README.md)                                                                           | Unknown     | ✅        | ✅               |
| [Stock_Exchange_Simulator](challenges/Stock_Exchange_Simulator/README.md)                                                     | Unknown     | ❌        | ❌               |
| [Street_map_service](challenges/Street_map_service/README.md)                                                                 | Unknown     | ✅        | ✅               |
| [String_Info_Calculator](challenges/String_Info_Calculator/README.md)                                                         | Unknown     | ✅        | ✅               |
| [String_Storage_and_Retrieval](challenges/String_Storage_and_Retrieval/README.md)                                             | Unknown     | ✅        | ✅               |
| [TAINTEDLOVE](challenges/TAINTEDLOVE/README.md)                                                                               | Unknown     | ✅        | ✅               |
| [TFTTP](challenges/TFTTP/README.md)                                                                                           | Unknown     | ❌        | ❌               |
| [TIACA](challenges/TIACA/README.md)                                                                                           | Unknown     | ✅        | ✅               |
| [TVS](challenges/TVS/README.md)                                                                                               | Unknown     | ✅        | ✅               |
| [Tennis_Ball_Motion_Calculator](challenges/Tennis_Ball_Motion_Calculator/README.md)                                           | Unknown     | ✅        | ✅               |
| [Terrible_Ticket_Tracker](challenges/Terrible_Ticket_Tracker/README.md)                                                       | Unknown     | ✅        | ✅               |
| [TextSearch](challenges/TextSearch/README.md)                                                                                 | Unknown     | ❌        | ❌               |
| [The_Longest_Road](challenges/The_Longest_Road/README.md)                                                                     | Unknown     | ❌        | ❌               |
| [Thermal_Controller_v2](challenges/Thermal_Controller_v2/README.md)                                                           | Unknown     | ✅        | ✅               |
| [Thermal_Controller_v3](challenges/Thermal_Controller_v3/README.md)                                                           | Unknown     | ✅        | ✅               |
| [Tick-A-Tack](challenges/Tick-A-Tack/README.md)                                                                               | Unknown     | ✅        | ✅               |
| [UTF-late](challenges/UTF-late/README.md)                                                                                     | Unknown     | ✅        | ✅               |
| [User_Manager](challenges/User_Manager/README.md)                                                                             | Unknown     | ✅        | ✅               |
| [ValveChecks](challenges/ValveChecks/README.md)                                                                               | Unknown     | ✅        | ✅               |
| [Vector_Graphics_2](challenges/Vector_Graphics_2/README.md)                                                                   | Unknown     | ✅        | ✅               |
| [Vector_Graphics_Format](challenges/Vector_Graphics_Format/README.md)                                                         | Unknown     | ✅        | ✅               |
| [Venture_Calculator](challenges/Venture_Calculator/README.md)                                                                 | Unknown     | ✅        | ✅               |
| [Virtual_Machine](challenges/Virtual_Machine/README.md)                                                                       | Unknown     | ✅        | ✅               |
| [Water_Treatment_Facility_Simulator](challenges/Water_Treatment_Facility_Simulator/README.md)                                 | Unknown     | ❌        | ❌               |
| [WhackJack](challenges/WhackJack/README.md)                                                                                   | Unknown     | ✅        | ✅               |
| [WordCompletion](challenges/WordCompletion/README.md)                                                                         | Unknown     | ✅        | ❌               |
| [XStore](challenges/XStore/README.md)                                                                                         | Unknown     | ✅        | ✅               |
| [anagram_game](challenges/anagram_game/README.md)                                                                             | CROMU_00005 | ✅        | ✅               |
| [basic_emulator](challenges/basic_emulator/README.md)                                                                         | CROMU_00012 | ✅        | ✅               |
| [basic_messaging](challenges/basic_messaging/README.md)                                                                       | CROMU_00014 | ✅        | ❌               |
| [chess_mimic](challenges/chess_mimic/README.md)                                                                               | CROMU_00033 | ✅        | ✅               |
| [commerce_webscale](challenges/commerce_webscale/README.md)                                                                   | CROMU_00038 | ❌        | ❌               |
| [cotton_swab_arithmetic](challenges/cotton_swab_arithmetic/README.md)                                                         | CROMU_00039 | ✅        | ✅               |
| [cyber_blogger](challenges/cyber_blogger/README.md)                                                                           | CROMU_00042 | ✅        | ✅               |
| [electronictrading](challenges/electronictrading/README.md)                                                                   | KPRCA_00014 | ✅        | ✅               |
| [greeter](challenges/greeter/README.md)                                                                                       | KPRCA_00038 | ✅        | ✅               |
| [hawaii_sets](challenges/hawaii_sets/README.md)                                                                               | KPRCA_00045 | ✅        | ❌               |
| [humaninterface](challenges/humaninterface/README.md)                                                                         | KPRCA_00051 | ✅        | ✅               |
| [matrices_for_sale](challenges/matrices_for_sale/README.md)                                                                   | NRFIN_00017 | ✅        | ✅               |
| [middleout](challenges/middleout/README.md)                                                                                   | NRFIN_00021 | ❌        | ❌               |
| [middleware_handshake](challenges/middleware_handshake/README.md)                                                             | NRFIN_00022 | ✅        | ✅               |
| [netstorage](challenges/netstorage/README.md)                                                                                 | NRFIN_00039 | ❌        | ❌               |
| [online_job_application](challenges/online_job_application/README.md)                                                         | Unknown     | ✅        | ✅               |
| [online_job_application2](challenges/online_job_application2/README.md)                                                       | Unknown     | ✅        | ✅               |
| [payroll](challenges/payroll/README.md)                                                                                       | Unknown     | ✅        | ❌               |
| [pizza_ordering_system](challenges/pizza_ordering_system/README.md)                                                           | Unknown     | ✅        | ✅               |
| [reallystream](challenges/reallystream/README.md)                                                                             | Unknown     | ❌        | ❌               |
| [root64_and_parcour](challenges/root64_and_parcour/README.md)                                                                 | Unknown     | ✅        | ✅               |
| [router_simulator](challenges/router_simulator/README.md)                                                                     | Unknown     | ✅        | ✅               |
| [simpleOCR](challenges/simpleOCR/README.md)                                                                                   | Unknown     | ✅        | ✅               |
| [simple_integer_calculator](challenges/simple_integer_calculator/README.md)                                                   | Unknown     | ✅        | ✅               |
| [simplenote](challenges/simplenote/README.md)                                                                                 | Unknown     | ✅        | ✅               |
| [stack_vm](challenges/stack_vm/README.md)                                                                                     | Unknown     | ✅        | ✅               |
| [stream_vm](challenges/stream_vm/README.md)                                                                                   | Unknown     | ✅        | ✅               |
| [stream_vm2](challenges/stream_vm2/README.md)                                                                                 | Unknown     | ✅        | ✅               |
| [tribute](challenges/tribute/README.md)                                                                                       | Unknown     | ❌        | ❌               |
| [university_enrollment](challenges/university_enrollment/README.md)                                                           | Unknown     | ❌        | ❌               |
| [vFilter](challenges/vFilter/README.md)                                                                                       | Unknown     | ✅        | ✅               |
| [virtual_pet](challenges/virtual_pet/README.md)                                                                               | Unknown     | ❌        | ❌               |
| [yolodex](challenges/yolodex/README.md)                                                                                       | Unknown     | ✅        | ✅               |
