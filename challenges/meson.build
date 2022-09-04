enabled = get_option('enabled')
disabled = get_option('disabled')
enable_broken = get_option('enable_broken')

broken = [
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

foreach challenge : enabled
    if challenge not in disabled
        if challenge in broken and enable_broken
                subdir(challenge)
        elif challenge not in broken
            subdir(challenge)
        endif
    endif
endforeach