/// LeptonKit - portable neutrino detector.
/// Nikolay Valentinovich Repnitskiy - License: WTFPLv2+ (wtfpl.net)


/* v1.0.0  Use device from  github.com/compromise-evident/LeptonKit  in order to
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
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//                                                                                                                          |
	bool printed_in_terminal = true; //DEFAULT = TRUE else no visual in terminal.                     no visual of broken >     |
	//                                                                                                                          |
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	
	in_stream.open("untitled.raw");
	if(in_stream.fail() == true) {cout << "no file"; return 0;}
	long long flash_of_light_counter = 0;
	long long first_500_000_bytes = 1;
	char temp_file_byte;
	in_stream.get(temp_file_byte);
	for(; in_stream.eof() == false;)
	{	in_stream.get(temp_file_byte);
		
		if(temp_file_byte > 95)
		{	if(printed_in_terminal == true)  {cout << " ";}
		}
		else
		{	if(printed_in_terminal == true)  {cout << "#";}
			if(first_500_000_bytes > 500000) {flash_of_light_counter++;}
		}
		
		//First few seconds are skipped in case you activated the tester LED as the very early
		//first activity in order to see if buggy Audacity is recording at that particular time.
		//Additionally, the first few seconds are skipped to allow recording hardware to settle.
		first_500_000_bytes++; //May serve secondary purpose in later versions (total Bytes.)
	}
	in_stream.close();
	
	//As you scroll through the visual output in the terminal, you'll see one '#' every long once in a while.
	//That's a flash of light bright enough to let current through the photoresistor and into the microphone line.
	//If observing my uploaded sample raw audio files, you'll see 3 groups of activity at the beginning in the terminal,
	//that's where I activated the tester LED and watched Audacity pick up 3 spikes. (It's good to know it's recording.)
	cout << "\n\n" << flash_of_light_counter << " flashes of light (skipped first few seconds.)";
}
