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
are essentially input seeds. It also provides a one-shot test for each binary, as many
binaries are broken (for example `cgc_malloc` from Kaprica does not run correctly and
the fix is to replace its body with a call to `malloc` but this is not done yet for all
binaries).

## Table of Contents

- [CGC Challenges](#cgc-challenges)
  - [Table of Contents](#table-of-contents)
  - [Build Instructions](#build-instructions)
    - [Install Dependencies](#install-dependencies)
    - [Compile Challenges](#compile-challenges)
    - [Install Challenges](#install-challenges)
    - [Test Challenges](#test-challenges)
  - [Customizing Build](#customizing-build)
    - [Change Output Directory](#change-output-directory)
    - [Custom Flags](#custom-flags)
    - [Turn off poll building](#turn-off-poll-building)
    - [Automatic Python2 Module Installs](#automatic-python2-module-installs)
    - [Enabling and Disabling Challenges](#enabling-and-disabling-challenges)
      - [Disable Challenges](#disable-challenges)
      - [Enable Challenges](#enable-challenges)
      - [Enable Broken Challenges](#enable-broken-challenges)
  - [Challenge Status](#challenge-status)

## Build Instructions

### Install Dependencies

```sh
$ sudo apt-get install meson ninja-build build-essential python2
```

### Compile Challenges

```sh
$ meson builddir
$ meson compile -C builddir
```

### Install Challenges

By default, challenges will be "installed" to `./output/`.

```sh
$ meson install -C builddir
```

### Test Challenges

You can test the challenges with their generated polls with:

```sh
$ meson test -C builddir
```

## Customizing Build

### Change Output Directory

You can specify a custom install directory with:

`meson "-Dinstall_path=/path/to/install/dir" builddir`

### Custom Flags


- Custom `CFLAGS` example: `meson -Dc_args='-fno-inline'`
- Custom `LDFLAGS` example: `meson -Dc_link_args='-fuse-ld=mold`

There are a lot of included build options that you can find [here](https://mesonbuild.com/Builtin-options.html)
probably, you will want:

- To enable/disable PIE: `-Db_pie=true` or `-Db_pie=false`
- NOTE: on some compilers for some reason, `b_pie` does not affect PIE executable building.
  in this case, you can use `-Dforce_nopie=true` to force no-pie building. This is
  tracked as issue [10885](https://github.com/mesonbuildmeson/issues/10885).

### Turn off poll building

Poll building can be disabled entirely with `meson -Dno_polls=true`

### Automatic Python2 Module Installs

Four Python2 modules are required to build this project's polls (which are basically
just input seeds):

* `pycryptodome`
* `pyyaml`
* `matplotlib`

These will *NOT* be installed automatically by default, but if you are missing these
modules *or* missing Python2 pip, the build system can install them for you and set
up Python2. Just pass `-Dinstall_pip_modules`.

### Enabling and Disabling Challenges

By default all working challenges are enabled and will be built. The build is reasonably fast, but you may for some reason want to disable challenges.

#### Disable Challenges

You can specify a list of challenges to disable with:

`meson "-Ddisable=['TFTTP', 'virtual_pet']" builddir`

All challenges are enabled by default, so adding a challenge to the list of disabled
challenges will toggle it off. The list of disabled challenges defaults to the list of
broken challenges, but if this option is passed the passed list will *not* override the
list of broken challenges unless `"-Denable_broken"` is also passed.

#### Enable Challenges

You can specify a list of challenges to enable with:

`meson "-Denable=['TFTTP', 'virtual_pet']" builddir`

*Only* challenges that are explicitly enabled will be built if this option is provided.

#### Enable Broken Challenges

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

| #   | Challenge                                                                                                                     | Codename    | Building | Polls Generated |
| --- | ----------------------------------------------------------------------------------------------------------------------------- | ----------- | -------- | --------------- |
| 0   | [0maker](challenges/0maker/README.md)                                                                                         | NRFIN_00014 | ❌        | ❌               |
| 1   | [3D_Image_Toolkit](challenges/3D_Image_Toolkit/README.md)                                                                     | CROMU_00001 | ✅        | ❌               |
| 2   | [AIS-Lite](challenges/AIS-Lite/README.md)                                                                                     | CROMU_00004 | ✅        | ✅               |
| 3   | [ASCII_Content_Server](challenges/ASCII_Content_Server/README.md)                                                             | CROMU_00006 | ✅        | ✅               |
| 4   | [ASL6parse](challenges/ASL6parse/README.md)                                                                                   | CROMU_00008 | ✅        | ✅               |
| 5   | [A_Game_of_Chance](challenges/A_Game_of_Chance/README.md)                                                                     | CROMU_00003 | ❌        | ❌               |
| 6   | [Accel](challenges/Accel/README.md)                                                                                           | CROMU_00002 | ❌        | ❌               |
| 7   | [Audio_Visualizer](challenges/Audio_Visualizer/README.md)                                                                     | CROMU_00009 | ✅        | ✅               |
| 8   | [Azurad](challenges/Azurad/README.md)                                                                                         | CROMU_00010 | ✅        | ❌               |
| 9   | [BIRC](challenges/BIRC/README.md)                                                                                             | CROMU_00015 | ❌        | ❌               |
| 10  | [Barcoder](challenges/Barcoder/README.md)                                                                                     | CROMU_00011 | ✅        | ✅               |
| 11  | [BitBlaster](challenges/BitBlaster/README.md)                                                                                 | CROMU_00016 | ✅        | ✅               |
| 12  | [Bloomy_Sunday](challenges/Bloomy_Sunday/README.md)                                                                           | CROMU_00017 | ✅        | ✅               |
| 13  | [Blubber](challenges/Blubber/README.md)                                                                                       | Unknown     | ❌        | ❌               |
| 14  | [Board_Game](challenges/Board_Game/README.md)                                                                                 | CROMU_00018 | ✅        | ✅               |
| 15  | [BudgIT](challenges/BudgIT/README.md)                                                                                         | CROMU_00019 | ✅        | ✅               |
| 16  | [CGC_Board](challenges/CGC_Board/README.md)                                                                                   | CROMU_00024 | ❌        | ❌               |
| 17  | [CGC_File_System](challenges/CGC_File_System/README.md)                                                                       | CROMU_00025 | ✅        | ❌               |
| 18  | [CGC_Hangman_Game](challenges/CGC_Hangman_Game/README.md)                                                                     | CROMU_00026 | ✅        | ✅               |
| 19  | [CGC_Image_Parser](challenges/CGC_Image_Parser/README.md)                                                                     | CROMU_00027 | ❌        | ❌               |
| 20  | [CGC_Planet_Markup_Language_Parser](challenges/CGC_Planet_Markup_Language_Parser/README.md)                                   | CROMU_00028 | ✅        | ❌               |
| 21  | [CGC_Symbol_Viewer_CSV](challenges/CGC_Symbol_Viewer_CSV/README.md)                                                           | CROMU_00029 | ✅        | ✅               |
| 22  | [CGC_Video_Format_Parser_and_Viewer](challenges/CGC_Video_Format_Parser_and_Viewer/README.md)                                 | CROMU_00030 | ✅        | ❌               |
| 23  | [CLOUDCOMPUTE](challenges/CLOUDCOMPUTE/README.md)                                                                             | CROMU_00035 | ❌        | ❌               |
| 24  | [CML](challenges/CML/README.md)                                                                                               | Unknown     | ❌        | ❌               |
| 25  | [CNMP](challenges/CNMP/README.md)                                                                                             | CROMU_00036 | ✅        | ✅               |
| 26  | [COLLIDEOSCOPE](challenges/COLLIDEOSCOPE/README.md)                                                                           | CROMU_00037 | ✅        | ✅               |
| 27  | [CTTP](challenges/CTTP/README.md)                                                                                             | CROMU_00041 | ✅        | ✅               |
| 28  | [CableGrind](challenges/CableGrind/README.md)                                                                                 | CROMU_00020 | ✅        | ✅               |
| 29  | [CableGrindLlama](challenges/CableGrindLlama/README.md)                                                                       | CROMU_00021 | ✅        | ✅               |
| 30  | [Carbonate](challenges/Carbonate/README.md)                                                                                   | Unknown     | ❌        | ❌               |
| 31  | [Casino_Games](challenges/Casino_Games/README.md)                                                                             | CROMU_00022 | ✅        | ✅               |
| 32  | [Cereal_Mixup__A_Cereal_Vending_Machine_Controller](challenges/Cereal_Mixup__A_Cereal_Vending_Machine_Controller/README.md)   | CROMU_00023 | ✅        | ✅               |
| 33  | [Character_Statistics](challenges/Character_Statistics/README.md)                                                             | CROMU_00031 | ✅        | ✅               |
| 34  | [Charter](challenges/Charter/README.md)                                                                                       | Unknown     | ❌        | ❌               |
| 35  | [Checkmate](challenges/Checkmate/README.md)                                                                                   | CROMU_00032 | ✅        | ✅               |
| 36  | [Childs_Game](challenges/Childs_Game/README.md)                                                                               | CROMU_00034 | ✅        | ✅               |
| 37  | [Corinth](challenges/Corinth/README.md)                                                                                       | Unknown     | ❌        | ❌               |
| 38  | [Cromulence_All_Service](challenges/Cromulence_All_Service/README.md)                                                         | CROMU_00040 | ✅        | ✅               |
| 39  | [DFARS_Sample_Service](challenges/DFARS_Sample_Service/README.md)                                                             | CROMU_00043 | ✅        | ✅               |
| 40  | [Diary_Parser](challenges/Diary_Parser/README.md)                                                                             | CROMU_00044 | ✅        | ✅               |
| 41  | [Differ](challenges/Differ/README.md)                                                                                         | KPRCA_00002 | ✅        | ✅               |
| 42  | [Diophantine_Password_Wallet](challenges/Diophantine_Password_Wallet/README.md)                                               | KPRCA_00007 | ✅        | ✅               |
| 43  | [Dive_Logger](challenges/Dive_Logger/README.md)                                                                               | KPRCA_00008 | ✅        | ✅               |
| 44  | [Divelogger2](challenges/Divelogger2/README.md)                                                                               | KPRCA_00009 | ✅        | ✅               |
| 45  | [Document_Rendering_Engine](challenges/Document_Rendering_Engine/README.md)                                                   | KPRCA_00010 | ✅        | ✅               |
| 46  | [Dungeon_Master](challenges/Dungeon_Master/README.md)                                                                         | KPRCA_00011 | ❌        | ❌               |
| 47  | [ECM_TCM_Simulator](challenges/ECM_TCM_Simulator/README.md)                                                                   | KPRCA_00012 | ✅        | ✅               |
| 48  | [Eddy](challenges/Eddy/README.md)                                                                                             | KPRCA_00013 | ✅        | ✅               |
| 49  | [Email_System_2](challenges/Email_System_2/README.md)                                                                         | KPRCA_00016 | ✅        | ✅               |
| 50  | [Enslavednode_chat](challenges/Enslavednode_chat/README.md)                                                                   | KPRCA_00017 | ❌        | ❌               |
| 51  | [Estadio](challenges/Estadio/README.md)                                                                                       | KPRCA_00018 | ✅        | ❌               |
| 52  | [EternalPass](challenges/EternalPass/README.md)                                                                               | KPRCA_00019 | ❌        | ❌               |
| 53  | [FASTLANE](challenges/FASTLANE/README.md)                                                                                     | KPRCA_00023 | ❌        | ❌               |
| 54  | [FISHYXML](challenges/FISHYXML/README.md)                                                                                     | KPRCA_00027 | ✅        | ✅               |
| 55  | [FSK_BBS](challenges/FSK_BBS/README.md)                                                                                       | KPRCA_00031 | ✅        | ✅               |
| 56  | [FSK_Messaging_Service](challenges/FSK_Messaging_Service/README.md)                                                           | KPRCA_00032 | ✅        | ✅               |
| 57  | [FUN](challenges/FUN/README.md)                                                                                               | KPRCA_00033 | ❌        | ❌               |
| 58  | [FablesReport](challenges/FablesReport/README.md)                                                                             | KPRCA_00020 | ✅        | ✅               |
| 59  | [FaceMag](challenges/FaceMag/README.md)                                                                                       | Unknown     | ❌        | ❌               |
| 60  | [Facilities_Access_Control_System](challenges/Facilities_Access_Control_System/README.md)                                     | KPRCA_00021 | ✅        | ✅               |
| 61  | [FailAV](challenges/FailAV/README.md)                                                                                         | KPRCA_00022 | ✅        | ✅               |
| 62  | [FileSys](challenges/FileSys/README.md)                                                                                       | KPRCA_00024 | ✅        | ✅               |
| 63  | [Filesystem_Command_Shell](challenges/Filesystem_Command_Shell/README.md)                                                     | KPRCA_00025 | ✅        | ✅               |
| 64  | [Finicky_File_Folder](challenges/Finicky_File_Folder/README.md)                                                               | KPRCA_00026 | ✅        | ✅               |
| 65  | [Flash_File_System](challenges/Flash_File_System/README.md)                                                                   | KPRCA_00028 | ✅        | ✅               |
| 66  | [Flight_Routes](challenges/Flight_Routes/README.md)                                                                           | KPRCA_00029 | ✅        | ✅               |
| 67  | [Fortress](challenges/Fortress/README.md)                                                                                     | KPRCA_00030 | ✅        | ✅               |
| 68  | [GPS_Tracker](challenges/GPS_Tracker/README.md)                                                                               | KPRCA_00036 | ✅        | ✅               |
| 69  | [GREYMATTER](challenges/GREYMATTER/README.md)                                                                                 | KPRCA_00039 | ✅        | ✅               |
| 70  | [Game_Night](challenges/Game_Night/README.md)                                                                                 | KPRCA_00034 | ✅        | ✅               |
| 71  | [Glue](challenges/Glue/README.md)                                                                                             | KPRCA_00035 | ✅        | ✅               |
| 72  | [GreatView](challenges/GreatView/README.md)                                                                                   | KPRCA_00037 | ✅        | ✅               |
| 73  | [Gridder](challenges/Gridder/README.md)                                                                                       | KPRCA_00040 | ✅        | ✅               |
| 74  | [Griswold](challenges/Griswold/README.md)                                                                                     | KPRCA_00041 | ❌        | ❌               |
| 75  | [Grit](challenges/Grit/README.md)                                                                                             | KPRCA_00042 | ✅        | ✅               |
| 76  | [H20FlowInc](challenges/H20FlowInc/README.md)                                                                                 | KPRCA_00043 | ✅        | ✅               |
| 77  | [HIGHCOO](challenges/HIGHCOO/README.md)                                                                                       | KPRCA_00048 | ✅        | ✅               |
| 78  | [HackMan](challenges/HackMan/README.md)                                                                                       | KPRCA_00044 | ✅        | ✅               |
| 79  | [Headscratch](challenges/Headscratch/README.md)                                                                               | KPRCA_00046 | ✅        | ✅               |
| 80  | [HeartThrob](challenges/HeartThrob/README.md)                                                                                 | KPRCA_00047 | ✅        | ✅               |
| 81  | [HighFrequencyTradingAlgo](challenges/HighFrequencyTradingAlgo/README.md)                                                     | KPRCA_00049 | ✅        | ✅               |
| 82  | [Hug_Game](challenges/Hug_Game/README.md)                                                                                     | KPRCA_00050 | ✅        | ✅               |
| 83  | [INSULATR](challenges/INSULATR/README.md)                                                                                     | KPRCA_00053 | ✅        | ✅               |
| 84  | [Image_Compressor](challenges/Image_Compressor/README.md)                                                                     | KPRCA_00052 | ✅        | ❌               |
| 85  | [KKVS](challenges/KKVS/README.md)                                                                                             | NRFIN_00004 | ❌        | ❌               |
| 86  | [KTY_Pretty_Printer](challenges/KTY_Pretty_Printer/README.md)                                                                 | NRFIN_00005 | ✅        | ✅               |
| 87  | [Kaprica_Go](challenges/Kaprica_Go/README.md)                                                                                 | KPRCA_00054 | ✅        | ❌               |
| 88  | [Kaprica_Script_Interpreter](challenges/Kaprica_Script_Interpreter/README.md)                                                 | NRFIN_00001 | ❌        | ❌               |
| 89  | [LAN_Simulator](challenges/LAN_Simulator/README.md)                                                                           | NRFIN_00006 | ❌        | ❌               |
| 90  | [LMS](challenges/LMS/README.md)                                                                                               | NRFIN_00009 | ✅        | ✅               |
| 91  | [LazyCalc](challenges/LazyCalc/README.md)                                                                                     | NRFIN_00008 | ✅        | ✅               |
| 92  | [Lazybox](challenges/Lazybox/README.md)                                                                                       | NRFIN_00007 | ❌        | ❌               |
| 93  | [Loud_Square_Instant_Messaging_Protocol_LSIMP](challenges/Loud_Square_Instant_Messaging_Protocol_LSIMP/README.md)             | NRFIN_00011 | ✅        | ✅               |
| 94  | [LulzChat](challenges/LulzChat/README.md)                                                                                     | NRFIN_00012 | ❌        | ❌               |
| 95  | [Material_Temperature_Simulation](challenges/Material_Temperature_Simulation/README.md)                                       | NRFIN_00015 | ✅        | ❌               |
| 96  | [Mathematical_Solver](challenges/Mathematical_Solver/README.md)                                                               | NRFIN_00016 | ✅        | ✅               |
| 97  | [Matrix_Math_Calculator](challenges/Matrix_Math_Calculator/README.md)                                                         | NRFIN_00018 | ✅        | ✅               |
| 98  | [Message_Service](challenges/Message_Service/README.md)                                                                       | NRFIN_00019 | ✅        | ❌               |
| 99  | [Messaging](challenges/Messaging/README.md)                                                                                   | NRFIN_00020 | ❌        | ❌               |
| 100 | [Mixology](challenges/Mixology/README.md)                                                                                     | Unknown     | ❌        | ❌               |
| 101 | [Modern_Family_Tree](challenges/Modern_Family_Tree/README.md)                                                                 | NRFIN_00023 | ✅        | ✅               |
| 102 | [Monster_Game](challenges/Monster_Game/README.md)                                                                             | NRFIN_00024 | ✅        | ✅               |
| 103 | [Mount_Filemore](challenges/Mount_Filemore/README.md)                                                                         | NRFIN_00025 | ✅        | ✅               |
| 104 | [Movie_Rental_Service](challenges/Movie_Rental_Service/README.md)                                                             | NRFIN_00026 | ✅        | ✅               |
| 105 | [Movie_Rental_Service_Redux](challenges/Movie_Rental_Service_Redux/README.md)                                                 | NRFIN_00027 | ✅        | ✅               |
| 106 | [Multi_Arena_Pursuit_Simulator](challenges/Multi_Arena_Pursuit_Simulator/README.md)                                           | NRFIN_00029 | ✅        | ✅               |
| 107 | [Multi_User_Calendar](challenges/Multi_User_Calendar/README.md)                                                               | NRFIN_00035 | ✅        | ✅               |
| 108 | [Multicast_Chat_Server](challenges/Multicast_Chat_Server/README.md)                                                           | NRFIN_00030 | ❌        | ❌               |
| 109 | [Multipass](challenges/Multipass/README.md)                                                                                   | NRFIN_00032 | ❌        | ❌               |
| 110 | [Multipass2](challenges/Multipass2/README.md)                                                                                 | NRFIN_00033 | ❌        | ❌               |
| 111 | [Multipass3](challenges/Multipass3/README.md)                                                                                 | NRFIN_00034 | ❌        | ❌               |
| 112 | [Music_Store_Client](challenges/Music_Store_Client/README.md)                                                                 | NRFIN_00036 | ✅        | ✅               |
| 113 | [NarfAgainShell](challenges/NarfAgainShell/README.md)                                                                         | NRFIN_00037 | ✅        | ✅               |
| 114 | [NarfRPN](challenges/NarfRPN/README.md)                                                                                       | NRFIN_00038 | ✅        | ✅               |
| 115 | [Network_File_System](challenges/Network_File_System/README.md)                                                               | NRFIN_00040 | ✅        | ❌               |
| 116 | [Network_File_System_v3](challenges/Network_File_System_v3/README.md)                                                         | NRFIN_00041 | ✅        | ✅               |
| 117 | [Network_Queuing_Simulator](challenges/Network_Queuing_Simulator/README.md)                                                   | NRFIN_00042 | ✅        | ❌               |
| 118 | [Neural_House](challenges/Neural_House/README.md)                                                                             | YAN01_00007 | ✅        | ✅               |
| 119 | [NoHiC](challenges/NoHiC/README.md)                                                                                           | YAN01_00009 | ❌        | ❌               |
| 120 | [No_Paper._Not_Ever._NOPE](challenges/No_Paper._Not_Ever._NOPE/README.md)                                                     | YAN01_00010 | ✅        | ✅               |
| 121 | [OTPSim](challenges/OTPSim/README.md)                                                                                         | Unknown     | ✅        | ✅               |
| 122 | [OUTLAW](challenges/OUTLAW/README.md)                                                                                         | Unknown     | ❌        | ❌               |
| 123 | [On_Sale](challenges/On_Sale/README.md)                                                                                       | Unknown     | ❌        | ❌               |
| 124 | [One_Amp](challenges/One_Amp/README.md)                                                                                       | YAN01_00011 | ✅        | ✅               |
| 125 | [One_Vote](challenges/One_Vote/README.md)                                                                                     | YAN01_00012 | ✅        | ✅               |
| 126 | [Order_Up](challenges/Order_Up/README.md)                                                                                     | Unknown     | ❌        | ❌               |
| 127 | [Overflow_Parking](challenges/Overflow_Parking/README.md)                                                                     | Unknown     | ✅        | ✅               |
| 128 | [PCM_Message_decoder](challenges/PCM_Message_decoder/README.md)                                                               | Unknown     | ✅        | ✅               |
| 129 | [PKK_Steganography](challenges/PKK_Steganography/README.md)                                                                   | Unknown     | ✅        | ✅               |
| 130 | [PRU](challenges/PRU/README.md)                                                                                               | Unknown     | ✅        | ✅               |
| 131 | [PTaaS](challenges/PTaaS/README.md)                                                                                           | Unknown     | ✅        | ❌               |
| 132 | [Pac_for_Edges](challenges/Pac_for_Edges/README.md)                                                                           | Unknown     | ✅        | ✅               |
| 133 | [Packet_Analyzer](challenges/Packet_Analyzer/README.md)                                                                       | Unknown     | ✅        | ✅               |
| 134 | [Packet_Receiver](challenges/Packet_Receiver/README.md)                                                                       | Unknown     | ✅        | ✅               |
| 135 | [Palindrome](challenges/Palindrome/README.md)                                                                                 | Unknown     | ✅        | ✅               |
| 136 | [Palindrome2](challenges/Palindrome2/README.md)                                                                               | Unknown     | ✅        | ✅               |
| 137 | [Parking_Permit_Management_System_PPMS](challenges/Parking_Permit_Management_System_PPMS/README.md)                           | Unknown     | ✅        | ✅               |
| 138 | [Particle_Simulator](challenges/Particle_Simulator/README.md)                                                                 | Unknown     | ✅        | ❌               |
| 139 | [Pattern_Finder](challenges/Pattern_Finder/README.md)                                                                         | Unknown     | ✅        | ✅               |
| 140 | [Personal_Fitness_Manager](challenges/Personal_Fitness_Manager/README.md)                                                     | Unknown     | ✅        | ✅               |
| 141 | [Pipelined](challenges/Pipelined/README.md)                                                                                   | Unknown     | ❌        | ❌               |
| 142 | [Printer](challenges/Printer/README.md)                                                                                       | Unknown     | ✅        | ✅               |
| 143 | [QUIETSQUARE](challenges/QUIETSQUARE/README.md)                                                                               | Unknown     | ✅        | ✅               |
| 144 | [QuadtreeConways](challenges/QuadtreeConways/README.md)                                                                       | Unknown     | ✅        | ✅               |
| 145 | [Query_Calculator](challenges/Query_Calculator/README.md)                                                                     | Unknown     | ❌        | ❌               |
| 146 | [RAM_based_filesystem](challenges/RAM_based_filesystem/README.md)                                                             | Unknown     | ❌        | ❌               |
| 147 | [REDPILL](challenges/REDPILL/README.md)                                                                                       | Unknown     | ❌        | ❌               |
| 148 | [REMATCH_1--Hat_Trick--Morris_Worm](challenges/REMATCH_1--Hat_Trick--Morris_Worm/README.md)                                   | Unknown     | ❌        | ❌               |
| 149 | [REMATCH_2--Mail_Server--Crackaddr](challenges/REMATCH_2--Mail_Server--Crackaddr/README.md)                                   | Unknown     | ✅        | ❌               |
| 150 | [REMATCH_3--Address_Resolution_Service--SQL_Slammer](challenges/REMATCH_3--Address_Resolution_Service--SQL_Slammer/README.md) | Unknown     | ✅        | ✅               |
| 151 | [REMATCH_4--CGCRPC_Server--MS08-067](challenges/REMATCH_4--CGCRPC_Server--MS08-067/README.md)                                 | Unknown     | ❌        | ❌               |
| 152 | [REMATCH_5--File_Explorer--LNK_Bug](challenges/REMATCH_5--File_Explorer--LNK_Bug/README.md)                                   | Unknown     | ✅        | ✅               |
| 153 | [REMATCH_6--Secure_Server--Heartbleed](challenges/REMATCH_6--Secure_Server--Heartbleed/README.md)                             | Unknown     | ✅        | ✅               |
| 154 | [RRPN](challenges/RRPN/README.md)                                                                                             | Unknown     | ✅        | ❌               |
| 155 | [Recipe_Database](challenges/Recipe_Database/README.md)                                                                       | Unknown     | ✅        | ✅               |
| 156 | [Recipe_and_Pantry_Manager](challenges/Recipe_and_Pantry_Manager/README.md)                                                   | Unknown     | ✅        | ❌               |
| 157 | [Rejistar](challenges/Rejistar/README.md)                                                                                     | Unknown     | ❌        | ❌               |
| 158 | [Resort_Modeller](challenges/Resort_Modeller/README.md)                                                                       | Unknown     | ✅        | ✅               |
| 159 | [SAuth](challenges/SAuth/README.md)                                                                                           | Unknown     | ✅        | ✅               |
| 160 | [SCUBA_Dive_Logging](challenges/SCUBA_Dive_Logging/README.md)                                                                 | Unknown     | ✅        | ✅               |
| 161 | [SFTSCBSISS](challenges/SFTSCBSISS/README.md)                                                                                 | Unknown     | ✅        | ✅               |
| 162 | [SIGSEGV](challenges/SIGSEGV/README.md)                                                                                       | Unknown     | ✅        | ✅               |
| 163 | [SLUR_reference_implementation](challenges/SLUR_reference_implementation/README.md)                                           | Unknown     | ✅        | ✅               |
| 164 | [SOLFEDGE](challenges/SOLFEDGE/README.md)                                                                                     | Unknown     | ✅        | ✅               |
| 165 | [SPIFFS](challenges/SPIFFS/README.md)                                                                                         | Unknown     | ✅        | ✅               |
| 166 | [Sad_Face_Template_Engine_SFTE](challenges/Sad_Face_Template_Engine_SFTE/README.md)                                           | Unknown     | ✅        | ✅               |
| 167 | [Sample_Shipgame](challenges/Sample_Shipgame/README.md)                                                                       | Unknown     | ✅        | ✅               |
| 168 | [Scrum_Database](challenges/Scrum_Database/README.md)                                                                         | Unknown     | ✅        | ✅               |
| 169 | [Secure_Compression](challenges/Secure_Compression/README.md)                                                                 | Unknown     | ✅        | ✅               |
| 170 | [Sensr](challenges/Sensr/README.md)                                                                                           | Unknown     | ✅        | ✅               |
| 171 | [Shipgame](challenges/Shipgame/README.md)                                                                                     | Unknown     | ❌        | ❌               |
| 172 | [Shortest_Path_Tree_Calculator](challenges/Shortest_Path_Tree_Calculator/README.md)                                           | Unknown     | ✅        | ✅               |
| 173 | [ShoutCTF](challenges/ShoutCTF/README.md)                                                                                     | Unknown     | ✅        | ✅               |
| 174 | [Simple_Stack_Machine](challenges/Simple_Stack_Machine/README.md)                                                             | Unknown     | ✅        | ✅               |
| 175 | [Single-Sign-On](challenges/Single-Sign-On/README.md)                                                                         | Unknown     | ❌        | ❌               |
| 176 | [Snail_Mail](challenges/Snail_Mail/README.md)                                                                                 | Unknown     | ✅        | ✅               |
| 177 | [Sorter](challenges/Sorter/README.md)                                                                                         | Unknown     | ✅        | ✅               |
| 178 | [Space_Attackers](challenges/Space_Attackers/README.md)                                                                       | Unknown     | ✅        | ✅               |
| 179 | [Square_Rabbit](challenges/Square_Rabbit/README.md)                                                                           | Unknown     | ✅        | ✅               |
| 180 | [Stock_Exchange_Simulator](challenges/Stock_Exchange_Simulator/README.md)                                                     | Unknown     | ❌        | ❌               |
| 181 | [Street_map_service](challenges/Street_map_service/README.md)                                                                 | Unknown     | ✅        | ✅               |
| 182 | [String_Info_Calculator](challenges/String_Info_Calculator/README.md)                                                         | Unknown     | ✅        | ✅               |
| 183 | [String_Storage_and_Retrieval](challenges/String_Storage_and_Retrieval/README.md)                                             | Unknown     | ✅        | ✅               |
| 184 | [TAINTEDLOVE](challenges/TAINTEDLOVE/README.md)                                                                               | Unknown     | ✅        | ✅               |
| 185 | [TFTTP](challenges/TFTTP/README.md)                                                                                           | Unknown     | ❌        | ❌               |
| 186 | [TIACA](challenges/TIACA/README.md)                                                                                           | Unknown     | ✅        | ✅               |
| 187 | [TVS](challenges/TVS/README.md)                                                                                               | Unknown     | ✅        | ✅               |
| 188 | [Tennis_Ball_Motion_Calculator](challenges/Tennis_Ball_Motion_Calculator/README.md)                                           | Unknown     | ✅        | ✅               |
| 189 | [Terrible_Ticket_Tracker](challenges/Terrible_Ticket_Tracker/README.md)                                                       | Unknown     | ✅        | ✅               |
| 190 | [TextSearch](challenges/TextSearch/README.md)                                                                                 | Unknown     | ❌        | ❌               |
| 191 | [The_Longest_Road](challenges/The_Longest_Road/README.md)                                                                     | Unknown     | ❌        | ❌               |
| 192 | [Thermal_Controller_v2](challenges/Thermal_Controller_v2/README.md)                                                           | Unknown     | ✅        | ✅               |
| 193 | [Thermal_Controller_v3](challenges/Thermal_Controller_v3/README.md)                                                           | Unknown     | ✅        | ✅               |
| 194 | [Tick-A-Tack](challenges/Tick-A-Tack/README.md)                                                                               | Unknown     | ✅        | ✅               |
| 195 | [UTF-late](challenges/UTF-late/README.md)                                                                                     | Unknown     | ✅        | ✅               |
| 196 | [User_Manager](challenges/User_Manager/README.md)                                                                             | Unknown     | ✅        | ✅               |
| 197 | [ValveChecks](challenges/ValveChecks/README.md)                                                                               | Unknown     | ✅        | ✅               |
| 198 | [Vector_Graphics_2](challenges/Vector_Graphics_2/README.md)                                                                   | Unknown     | ✅        | ✅               |
| 199 | [Vector_Graphics_Format](challenges/Vector_Graphics_Format/README.md)                                                         | Unknown     | ✅        | ✅               |
| 200 | [Venture_Calculator](challenges/Venture_Calculator/README.md)                                                                 | Unknown     | ✅        | ✅               |
| 201 | [Virtual_Machine](challenges/Virtual_Machine/README.md)                                                                       | Unknown     | ✅        | ✅               |
| 202 | [Water_Treatment_Facility_Simulator](challenges/Water_Treatment_Facility_Simulator/README.md)                                 | Unknown     | ❌        | ❌               |
| 203 | [WhackJack](challenges/WhackJack/README.md)                                                                                   | Unknown     | ✅        | ✅               |
| 204 | [WordCompletion](challenges/WordCompletion/README.md)                                                                         | Unknown     | ✅        | ❌               |
| 205 | [XStore](challenges/XStore/README.md)                                                                                         | Unknown     | ✅        | ✅               |
| 206 | [anagram_game](challenges/anagram_game/README.md)                                                                             | CROMU_00005 | ✅        | ✅               |
| 207 | [basic_emulator](challenges/basic_emulator/README.md)                                                                         | CROMU_00012 | ✅        | ✅               |
| 208 | [basic_messaging](challenges/basic_messaging/README.md)                                                                       | CROMU_00014 | ✅        | ❌               |
| 209 | [chess_mimic](challenges/chess_mimic/README.md)                                                                               | CROMU_00033 | ✅        | ✅               |
| 210 | [commerce_webscale](challenges/commerce_webscale/README.md)                                                                   | CROMU_00038 | ❌        | ❌               |
| 211 | [cotton_swab_arithmetic](challenges/cotton_swab_arithmetic/README.md)                                                         | CROMU_00039 | ✅        | ✅               |
| 212 | [cyber_blogger](challenges/cyber_blogger/README.md)                                                                           | CROMU_00042 | ✅        | ✅               |
| 213 | [electronictrading](challenges/electronictrading/README.md)                                                                   | KPRCA_00014 | ✅        | ✅               |
| 214 | [greeter](challenges/greeter/README.md)                                                                                       | KPRCA_00038 | ✅        | ✅               |
| 215 | [hawaii_sets](challenges/hawaii_sets/README.md)                                                                               | KPRCA_00045 | ✅        | ❌               |
| 216 | [humaninterface](challenges/humaninterface/README.md)                                                                         | KPRCA_00051 | ✅        | ✅               |
| 217 | [matrices_for_sale](challenges/matrices_for_sale/README.md)                                                                   | NRFIN_00017 | ✅        | ✅               |
| 218 | [middleout](challenges/middleout/README.md)                                                                                   | NRFIN_00021 | ❌        | ❌               |
| 219 | [middleware_handshake](challenges/middleware_handshake/README.md)                                                             | NRFIN_00022 | ✅        | ✅               |
| 220 | [netstorage](challenges/netstorage/README.md)                                                                                 | NRFIN_00039 | ❌        | ❌               |
| 221 | [online_job_application](challenges/online_job_application/README.md)                                                         | Unknown     | ✅        | ✅               |
| 222 | [online_job_application2](challenges/online_job_application2/README.md)                                                       | Unknown     | ✅        | ✅               |
| 223 | [payroll](challenges/payroll/README.md)                                                                                       | Unknown     | ✅        | ❌               |
| 224 | [pizza_ordering_system](challenges/pizza_ordering_system/README.md)                                                           | Unknown     | ✅        | ✅               |
| 225 | [reallystream](challenges/reallystream/README.md)                                                                             | Unknown     | ❌        | ❌               |
| 226 | [root64_and_parcour](challenges/root64_and_parcour/README.md)                                                                 | Unknown     | ✅        | ✅               |
| 227 | [router_simulator](challenges/router_simulator/README.md)                                                                     | Unknown     | ✅        | ✅               |
| 228 | [simpleOCR](challenges/simpleOCR/README.md)                                                                                   | Unknown     | ✅        | ✅               |
| 229 | [simple_integer_calculator](challenges/simple_integer_calculator/README.md)                                                   | Unknown     | ✅        | ✅               |
| 230 | [simplenote](challenges/simplenote/README.md)                                                                                 | Unknown     | ✅        | ✅               |
| 231 | [stack_vm](challenges/stack_vm/README.md)                                                                                     | Unknown     | ✅        | ✅               |
| 232 | [stream_vm](challenges/stream_vm/README.md)                                                                                   | Unknown     | ✅        | ✅               |
| 233 | [stream_vm2](challenges/stream_vm2/README.md)                                                                                 | Unknown     | ✅        | ✅               |
| 234 | [tribute](challenges/tribute/README.md)                                                                                       | Unknown     | ❌        | ❌               |
| 235 | [university_enrollment](challenges/university_enrollment/README.md)                                                           | Unknown     | ❌        | ❌               |
| 236 | [vFilter](challenges/vFilter/README.md)                                                                                       | Unknown     | ✅        | ✅               |
| 237 | [virtual_pet](challenges/virtual_pet/README.md)                                                                               | Unknown     | ❌        | ❌               |
| 238 | [yolodex](challenges/yolodex/README.md)                                                                                       | Unknown     | ✅        | ✅               |

