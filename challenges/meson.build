enabled = get_option('enabled')
disabled = get_option('disabled')
enable_broken = get_option('enable_broken')

broken = [
    # Disabled due to build errors
    'Accel',
    'A_Game_of_Chance',
    'BIRC',
    'Blubber',
    'Carbonate',
    'CGC_Board',
    'CGC_Image_Parser',
    'Charter',
    'CLOUDCOMPUTE',
    'CML',
    'commerce_webscale',
    'Corinth',
    'Dungeon_Master',
    'Enslavednode_chat',
    'EternalPass',
    'FaceMag',
    'FASTLANE',
    'FUN',
    'Griswold',
    'Kaprica_Script_Interpreter',
    'KKVS',
    'LAN_Simulator',
    'Lazybox',
    'LulzChat',
    'Messaging',
    'middleout',
    'Mixology',
    'Multicast_Chat_Server',
    'Multipass',
    'Multipass2',
    'Multipass3',
    'netstorage',
    'NoHiC',
    'On_Sale',
    'Order_Up',
    'OUTLAW',
    'OUTLAW_3',
    'Pipelined',
    'Query_Calculator',
    'RAM_based_filesystem',
    'reallystream',
    'REDPILL',
    'Rejistar',
    'REMATCH_1--Hat_Trick--Morris_Worm',
    'REMATCH_4--CGCRPC_Server--MS08-067',
    'Shipgame',
    'Single-Sign-On',
    'Stock_Exchange_Simulator',
    'TextSearch',
    'TFTTP',
    'The_Longest_Road',
    'tribute',
    'university_enrollment',
    'virtual_pet',
    'Water_Treatment_Facility_Simulator',
]

polls_broken = [
    # Disabled due to poller errors -- rely on dll for pollgen
    '3D_Image_Toolkit',
    'Azurad',
    'Estadio',
    'Image_Compressor',
    'Lazybox',
    'Material_Temperature_Simulation',
    'Network_File_System',
    'Network_Queuing_Simulator',
    'PTaaS',
    'REMATCH_2--Mail_Server--Crackaddr',
    'RRPN',
    'Recipe_and_Pantry_Manager',
    'payroll',
    'WordCompletion',
    # Output error
    'One_Vote',
    'Snail_Mail',
]

challenges_directory = meson.current_source_dir()
challenges_to_build = []
challenges_force_nopie = get_option('force_nopie')
build_pie = get_option('b_pie')
if not build_pie or challenges_force_nopie
    challenges_pie = false
    challenges_extra_c_args = ['-no-pie']
else
    challenges_pie = true
    challenges_extra_c_args = []
endif

foreach challenge : enabled
    if challenge not in disabled
        if challenge in broken and enable_broken
            challenges_to_build += challenge
        elif challenge not in broken
            challenges_to_build += challenge
        endif
    endif
endforeach

foreach challenge : challenges_to_build
    subdir(challenge)
endforeach