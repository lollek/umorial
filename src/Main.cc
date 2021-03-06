#include <iostream>
#include <limits>
#include <string>
#include <cstdlib>
#include <ctime>

#include <getopt.h>

#include "Game.hh"

using namespace std;

int main(int argc, char *argv[])
{
  string savefile;
  unsigned seed = 0;
  int c;

  /* Check commandline arguments */
  while ((c = getopt(argc, argv, "NnSsW:w:")) != -1)
    switch(c)
    {
      case 'N': case 'n':
        /* New game */
        cout << "Received option: New game\n";
        break;

      case 'S': case 's':
        /* Display Score */
        cout << "Displaying score and exiting\n";
        break;

      case 'W': case 'w':
        cout << "Entering wizard mode\n";
        /* Wizard mode */
        seed = stoi(optarg);
        if (seed == 0)
          cerr << "Bad seed received, ignoring\n";
        break;

      default: 
        cerr << "Usage: moria [-nsw] [savefile]\n";
        return 1;
    }

  /* Set savefile */
  if (argc - optind == 1)
    savefile = argv[optind];
  else if (argc - optind == 0)
  {
    char *home_dir = getenv("HOME");
    if (home_dir != NULL)
    {
      savefile = home_dir;
      savefile += "/.moria_save";
    }
    else
    {
      cerr << "Failed to find your home directory. Try setting a manual path\n";
      exit(1);
    }
  }
  else
  {
    cerr << "Usage: moria [-nsw] [savefile]\n";
    return 1;
  }

  /* Seed the game */
  srand(time(NULL)); /* This is THE seed in this game. Don't move */
  if (seed == 0)
    seed = rand() % numeric_limits<unsigned>::max();

  Game game(savefile, seed);
  return game.run();
}
