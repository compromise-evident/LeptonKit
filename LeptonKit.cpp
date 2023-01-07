/// LeptonKit - portable neutrino detector.
/// Nikolay Valentinovich Repnitskiy - License: WTFPLv2+ (wtfpl.net)


/* v2.0.0  Use device from  github.com/compromise-evident/LeptonKit  in order to
record with Audacity, then export recording as  "other uncompressed files"  with

      Header:  RAW (header-less)
    Encoding:  Unsigned 8-bit PCM

Now have LeptonKit.cpp take a look at the recording. It displays ## to represent
activity. Longer stretches of #### means more light. Based on my experience with
building RICINoptic, LeptonKit.cpp is sure when it says:   "n flashes of light".
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In the future, FBI surveillance vans  will use fusion-powered listening devices.
And fusion can be detected by observing emitted neutrinos.  Maybe one day you'll
walk around with lead pipes connected to your phone and get thermal-like visuals
of nearby HH power supplies.   github.com/compromise-evident/LeptonKit#what-next
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
How to run the program  -  Software package repositories for GNU+Linux operating
systems have all the tools you can imagine. Open a terminal and use this command
as root to install Geany and g++ on your computer: apt install geany g++   Geany
is a fast & lightweight text editor and Integrated Development Environment where
you can write and run code. g++ is the GNU compiler for C++ which allows written
code to run. The compiler operates in the background and displays errors in your
code as you will see in the lower Geany box. Make a new folder somewhere on your
machine. Paste this code into Geany. For clarity in auditing, enable indentation
guides: go to View >> Show Indentation Guides. Save the document as anything.cpp
within the newly-created folder. Use these shortcuts to run the program: F9, F5.
You may paste over this code with other  .cpp files, or open a new tab & repeat.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
How to make an executable with g++  -  Save this program as anything.cpp, open a
terminal, and type g++ then space. Drag & drop this saved file into the terminal
and its directory will be  appended to your pending entry. Click on the terminal
and press enter.   a.out now resides in the user directory, you may rename it to
anything.  To run that executable, simply drag and drop it into a terminal, then
click on the terminal and press enter.  Reminder:  executable's effect-directory
is /home/user or where you put the executable. Opening  .cpp  files in Geany and
hitting F9 creates the same executable--movable, renameable, drag & droppable.*/

#include <fstream>
#include <iostream>
using namespace std;

int main()
{	ifstream in_stream;
	ofstream out_stream;
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//                                                                                                                            |
	bool printed_in_terminal = false; //DEFAULT = FALSE else lengthy visual in terminal.                no visual if broken >     |
	//                                                                                                                            |
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	
	for(;;)
	{	//Gets path to file from user.
		cout << "\nDrag & drop file into terminal or enter path:\n";
		
		char  path_to_file[10000];
		for(int a = 0; a < 10000; a++) {path_to_file[a] = '\0';} //Fills path_to_file[] with null.
		cin.getline(path_to_file, 10000);
		if(path_to_file[0] == '\0') {cout << "\nNo path given.\n"; return 0;}
		
		//Fixes path to file if drag & dropped (removes single quotes for ex:)   '/home/nikolay/my documents/untitled.raw'
		if(path_to_file[0] == '\'')
		{	for(int a = 0; a < 10000; a++)
			{	path_to_file[a] = path_to_file[a + 1];
				if(path_to_file[a] == '\'')
				{	path_to_file[a    ] = '\0';
					path_to_file[a + 1] = '\0';
					path_to_file[a + 2] = '\0';
					break;
				}
			}
		}
		
		//Checks if file exists (failure can be bad path info as well.)
		in_stream.open(path_to_file);
		if(in_stream.fail() == true) {in_stream.close(); cout << "\n\nNo such file or directory.\n";             continue;}
		char sniffed_one_file_character;
		in_stream.get(sniffed_one_file_character);
		if(in_stream.eof() == true) {in_stream.close();  cout << "\n\nNothing to process, the file is empty.\n"; continue;}
		in_stream.close();
		
		//Processes file.
		in_stream.open(path_to_file);
		if(in_stream.fail() == true) {cout << "no file"; return 0;}
		long long flash_of_light_counter = 0;
		long long total_bytes = 0;
		char temp_file_byte;
		int  file_byte_normal;
		in_stream.get(temp_file_byte);
		for(; in_stream.eof() == false;)
		{	//..........Fixes Byte.
			file_byte_normal = temp_file_byte;
			if(file_byte_normal < 0) {file_byte_normal += 256;}
			
			if(file_byte_normal == 128)
			{	if(printed_in_terminal == true)  {cout << "#";}
				if(total_bytes > 500000) {flash_of_light_counter++;}
			}
			else
			{	if(printed_in_terminal == true)  {cout << " ";}
			}
			
			//First few seconds are skipped in case you activated the tester LED as the very early
			//first activity in order to see if buggy Audacity is recording at that particular time.
			//Additionally, the first few seconds are skipped to allow recording hardware to settle.
			total_bytes++;
			
			in_stream.get(temp_file_byte);
		}
		in_stream.close();
		
		//As you scroll through the visual output in the terminal, you'll see one '#' every long once in a while.
		//That's a flash of light bright enough to let current through the photoresistor and into the microphone line.
		//If observing my uploaded sample raw audio files, you'll see 3 groups of activity at the beginning in the terminal,
		//that's where I activated the tester LED and watched Audacity pick up 3 spikes. (It's good to know it's recording.)
		if(printed_in_terminal == true) {cout << "\n\n";}
		cout << flash_of_light_counter << " flashes of light (skipped first few seconds, " << total_bytes << " Bytes total)\n\n";
	}
}
