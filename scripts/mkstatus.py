"""Generate the status table for challenges

Requires a built `output` directory
"""

KNOWN_CHALLENGE_IDS = {
    "0maker": "NRFIN_00014",
    "3D_Image_Toolkit": "CROMU_00001",
    "AIS-Lite": "CROMU_00004",
    "ASCII_Content_Server": "CROMU_00006",
    "ASL6parse": "CROMU_00008",
    "A_Game_of_Chance": "CROMU_00003",
    "Accel": "CROMU_00002",
    "Audio_Visualizer": "CROMU_00009",
    "Azurad": "CROMU_00010",
    "BIRC": "CROMU_00015",
    "Barcoder": "CROMU_00011",
    "BitBlaster": "CROMU_00016",
    "Bloomy_Sunday": "CROMU_00017",
    "Blubber": "Unknown",
    "Board_Game": "CROMU_00018",
    "BudgIT": "CROMU_00019",
    "CGC_Board": "CROMU_00024",
    "CGC_File_System": "CROMU_00025",
    "CGC_Hangman_Game": "CROMU_00026",
    "CGC_Image_Parser": "CROMU_00027",
    "CGC_Planet_Markup_Language_Parser": "CROMU_00028",
    "CGC_Symbol_Viewer_CSV": "CROMU_00029",
    "CGC_Video_Format_Parser_and_Viewer": "CROMU_00030",
    "CLOUDCOMPUTE": "CROMU_00035",
    "CML": "Unknown",
    "CNMP": "CROMU_00036",
    "COLLIDEOSCOPE": "CROMU_00037",
    "CTTP": "CROMU_00041",
    "CableGrind": "CROMU_00020",
    "CableGrindLlama": "CROMU_00021",
    "Carbonate": "Unknown",
    "Casino_Games": "CROMU_00022",
    "Cereal_Mixup__A_Cereal_Vending_Machine_Controller": "CROMU_00023",
    "Character_Statistics": "CROMU_00031",
    "Charter": "Unknown",
    "Checkmate": "CROMU_00032",
    "Childs_Game": "CROMU_00034",
    "Corinth": "Unknown",
    "Cromulence_All_Service": "CROMU_00040",
    "DFARS_Sample_Service": "CROMU_00043",
    "Diary_Parser": "CROMU_00044",
    "Differ": "KPRCA_00002",
    "Diophantine_Password_Wallet": "KPRCA_00007",
    "Dive_Logger": "KPRCA_00008",
    "Divelogger2": "KPRCA_00009",
    "Document_Rendering_Engine": "KPRCA_00010",
    "Dungeon_Master": "KPRCA_00011",
    "ECM_TCM_Simulator": "KPRCA_00012",
    "Eddy": "KPRCA_00013",
    "Email_System_2": "KPRCA_00016",
    "Enslavednode_chat": "KPRCA_00017",
    "Estadio": "KPRCA_00018",
    "EternalPass": "KPRCA_00019",
    "FASTLANE": "KPRCA_00023",
    "FISHYXML": "KPRCA_00027",
    "FSK_BBS": "KPRCA_00031",
    "FSK_Messaging_Service": "KPRCA_00032",
    "FUN": "KPRCA_00033",
    "FablesReport": "KPRCA_00020",
    "FaceMag": "Unknown",
    "Facilities_Access_Control_System": "KPRCA_00021",
    "FailAV": "KPRCA_00022",
    "FileSys": "KPRCA_00024",
    "Filesystem_Command_Shell": "KPRCA_00025",
    "Finicky_File_Folder": "KPRCA_00026",
    "Flash_File_System": "KPRCA_00028",
    "Flight_Routes": "KPRCA_00029",
    "Fortress": "KPRCA_00030",
    "GPS_Tracker": "KPRCA_00036",
    "GREYMATTER": "KPRCA_00039",
    "Game_Night": "KPRCA_00034",
    "Glue": "KPRCA_00035",
    "GreatView": "KPRCA_00037",
    "Gridder": "KPRCA_00040",
    "Griswold": "KPRCA_00041",
    "Grit": "KPRCA_00042",
    "H20FlowInc": "KPRCA_00043",
    "HIGHCOO": "KPRCA_00048",
    "HackMan": "KPRCA_00044",
    "Headscratch": "KPRCA_00046",
    "HeartThrob": "KPRCA_00047",
    "HighFrequencyTradingAlgo": "KPRCA_00049",
    "Hug_Game": "KPRCA_00050",
    "INSULATR": "KPRCA_00053",
    "Image_Compressor": "KPRCA_00052",
    "KKVS": "NRFIN_00004",
    "KTY_Pretty_Printer": "NRFIN_00005",
    "Kaprica_Go": "KPRCA_00054",
    "Kaprica_Script_Interpreter": "NRFIN_00001",
    "LAN_Simulator": "NRFIN_00006",
    "LMS": "NRFIN_00009",
    "LazyCalc": "NRFIN_00008",
    "Lazybox": "NRFIN_00007",
    "Loud_Square_Instant_Messaging_Protocol_LSIMP": "NRFIN_00011",
    "LulzChat": "NRFIN_00012",
    "Material_Temperature_Simulation": "NRFIN_00015",
    "Mathematical_Solver": "NRFIN_00016",
    "Matrix_Math_Calculator": "NRFIN_00018",
    "Message_Service": "NRFIN_00019",
    "Messaging": "NRFIN_00020",
    "Mixology": "Unknown",
    "Modern_Family_Tree": "NRFIN_00023",
    "Monster_Game": "NRFIN_00024",
    "Mount_Filemore": "NRFIN_00025",
    "Movie_Rental_Service": "NRFIN_00026",
    "Movie_Rental_Service_Redux": "NRFIN_00027",
    "Multi_Arena_Pursuit_Simulator": "NRFIN_00029",
    "Multi_User_Calendar": "NRFIN_00035",
    "Multicast_Chat_Server": "NRFIN_00030",
    "Multipass": "NRFIN_00032",
    "Multipass2": "NRFIN_00033",
    "Multipass3": "NRFIN_00034",
    "Music_Store_Client": "NRFIN_00036",
    "NarfAgainShell": "NRFIN_00037",
    "NarfRPN": "NRFIN_00038",
    "Network_File_System": "NRFIN_00040",
    "Network_File_System_v3": "NRFIN_00041",
    "Network_Queuing_Simulator": "NRFIN_00042",
    "Neural_House": "YAN01_00007",
    "NoHiC": "YAN01_00009",
    "No_Paper._Not_Ever._NOPE": "YAN01_00010",
    "OTPSim": "Unknown",
    "OUTLAW": "Unknown",
    "On_Sale": "Unknown",
    "One_Amp": "YAN01_00011",
    "One_Vote": "YAN01_00012",
    "Order_Up": "Unknown",
    "Overflow_Parking": "Unknown",
    "PCM_Message_decoder": "Unknown",
    "PKK_Steganography": "Unknown",
    "PRU": "Unknown",
    "PTaaS": "Unknown",
    "Pac_for_Edges": "Unknown",
    "Packet_Analyzer": "Unknown",
    "Packet_Receiver": "Unknown",
    "Palindrome": "Unknown",
    "Palindrome2": "Unknown",
    "Parking_Permit_Management_System_PPMS": "Unknown",
    "Particle_Simulator": "Unknown",
    "Pattern_Finder": "Unknown",
    "Personal_Fitness_Manager": "Unknown",
    "Pipelined": "Unknown",
    "Printer": "Unknown",
    "QUIETSQUARE": "Unknown",
    "QuadtreeConways": "Unknown",
    "Query_Calculator": "Unknown",
    "RAM_based_filesystem": "Unknown",
    "REDPILL": "Unknown",
    "REMATCH_1--Hat_Trick--Morris_Worm": "Unknown",
    "REMATCH_2--Mail_Server--Crackaddr": "Unknown",
    "REMATCH_3--Address_Resolution_Service--SQL_Slammer": "Unknown",
    "REMATCH_4--CGCRPC_Server--MS08-067": "Unknown",
    "REMATCH_5--File_Explorer--LNK_Bug": "Unknown",
    "REMATCH_6--Secure_Server--Heartbleed": "Unknown",
    "RRPN": "Unknown",
    "Recipe_Database": "Unknown",
    "Recipe_and_Pantry_Manager": "Unknown",
    "Rejistar": "Unknown",
    "Resort_Modeller": "Unknown",
    "SAuth": "Unknown",
    "SCUBA_Dive_Logging": "Unknown",
    "SFTSCBSISS": "Unknown",
    "SIGSEGV": "Unknown",
    "SLUR_reference_implementation": "Unknown",
    "SOLFEDGE": "Unknown",
    "SPIFFS": "Unknown",
    "Sad_Face_Template_Engine_SFTE": "Unknown",
    "Sample_Shipgame": "Unknown",
    "Scrum_Database": "Unknown",
    "Secure_Compression": "Unknown",
    "Sensr": "Unknown",
    "Shipgame": "Unknown",
    "Shortest_Path_Tree_Calculator": "Unknown",
    "ShoutCTF": "Unknown",
    "Simple_Stack_Machine": "Unknown",
    "Single-Sign-On": "Unknown",
    "Snail_Mail": "Unknown",
    "Sorter": "Unknown",
    "Space_Attackers": "Unknown",
    "Square_Rabbit": "Unknown",
    "Stock_Exchange_Simulator": "Unknown",
    "Street_map_service": "Unknown",
    "String_Info_Calculator": "Unknown",
    "String_Storage_and_Retrieval": "Unknown",
    "TAINTEDLOVE": "Unknown",
    "TFTTP": "Unknown",
    "TIACA": "Unknown",
    "TVS": "Unknown",
    "Tennis_Ball_Motion_Calculator": "Unknown",
    "Terrible_Ticket_Tracker": "Unknown",
    "TextSearch": "Unknown",
    "The_Longest_Road": "Unknown",
    "Thermal_Controller_v2": "Unknown",
    "Thermal_Controller_v3": "Unknown",
    "Tick-A-Tack": "Unknown",
    "UTF-late": "Unknown",
    "User_Manager": "Unknown",
    "ValveChecks": "Unknown",
    "Vector_Graphics_2": "Unknown",
    "Vector_Graphics_Format": "Unknown",
    "Venture_Calculator": "Unknown",
    "Virtual_Machine": "Unknown",
    "Water_Treatment_Facility_Simulator": "Unknown",
    "WhackJack": "Unknown",
    "WordCompletion": "Unknown",
    "XStore": "Unknown",
    "anagram_game": "CROMU_00005",
    "basic_emulator": "CROMU_00012",
    "basic_messaging": "CROMU_00014",
    "chess_mimic": "CROMU_00033",
    "commerce_webscale": "CROMU_00038",
    "cotton_swab_arithmetic": "CROMU_00039",
    "cyber_blogger": "CROMU_00042",
    "electronictrading": "KPRCA_00014",
    "greeter": "KPRCA_00038",
    "hawaii_sets": "KPRCA_00045",
    "humaninterface": "KPRCA_00051",
    "matrices_for_sale": "NRFIN_00017",
    "middleout": "NRFIN_00021",
    "middleware_handshake": "NRFIN_00022",
    "netstorage": "NRFIN_00039",
    "online_job_application": "Unknown",
    "online_job_application2": "Unknown",
    "payroll": "Unknown",
    "pizza_ordering_system": "Unknown",
    "reallystream": "Unknown",
    "root64_and_parcour": "Unknown",
    "router_simulator": "Unknown",
    "simpleOCR": "Unknown",
    "simple_integer_calculator": "Unknown",
    "simplenote": "Unknown",
    "stack_vm": "Unknown",
    "stream_vm": "Unknown",
    "stream_vm2": "Unknown",
    "tribute": "Unknown",
    "university_enrollment": "Unknown",
    "vFilter": "Unknown",
    "virtual_pet": "Unknown",
    "yolodex": "Unknown",
}


from argparse import ArgumentParser
from dataclasses import dataclass
from pathlib import Path
from typing import Tuple


@dataclass
class ChallengeStatus:
    name: str
    codename: str
    building: bool
    polls: bool

    def tostr(self, widths: Tuple[int, int, int, int]) -> str:
        check = "\u2705"
        cross = "\u274C"
        return (
            f"| {self.name:<{widths[0]}} | {self.codename:<{widths[1]}} | "
            f"{check if self.building else cross:<{widths[2]}} | {check if self.polls else cross:<{widths[3]}} |"
        )


def main(output_dir: Path) -> None:
    """Generate the status table

    Args:
        output_dir: The output directory
    """
    status = []
    for chal, ident in KNOWN_CHALLENGE_IDS.items():
        name = f"[{chal}](challenges/{chal}/README.md)"
        codename = ident
        building = (output_dir / "bin" / chal).is_file()
        polls = (output_dir / "share" / "polls" / chal).is_dir()
        status.append(ChallengeStatus(name, codename, building, polls))

    widths = (
        max(map(lambda x: len(x.name), status)),
        max(map(lambda x: len(x.codename), status)),
        len("Building"),
        len("Polls Generated"),
    )

    print(
        f"| {'Challenge':<{widths[0]}} | {'Codename':<{widths[1]}} | "
        f"{'Building':<{widths[2]}} | {'Polls Generated':<{widths[3]}} |"
    )

    print(
        f"| {'-' * widths[0]} | {'-' * widths[1]} | "
        f"{'-' * widths[2]} | {'-' * widths[3]} |"
    )

    for s in status:
        print(s.tostr(widths))


if __name__ == "__main__":
    parser = ArgumentParser()

    parser.add_argument(
        "--output-dir",
        type=Path,
        required=False,
        default=Path(__file__).parents[1] / "output",
        help="Path to the cgc-challenges install directory. Defaults to the `output` directory.",
    )

    args = parser.parse_args()

    main(args.output_dir)
