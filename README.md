# Purpose: To work together on a game with a theme of "Freedom"

  Team Size: 9. If you don't have 9 people, the project director can choose
  which roles to skip.

  The project director should create a public GitHub repo and invite his/her
  teammates to collaborate on the project. Invite me as well.

  Points:
  20 Points (Group) -

  Quality of the Game. It needs to have all the pieces
  integrated together and available for download on Github. The game must be
  fun, have a victory condition, the ability to lose, at least 5 puzzles, a
  world map, colors, and a soundtrack. It must represent the tenets of freedom,
  which includes the right to life, liberty, property, and free market forces /
  Laissez-Faire Capitalism (get rekt Keynes).

  By Day 1, all people need to make an initial commit to the
  repo stating what their Role is, to the README.md.

  20 Points (Individual) -

  Person 1: Scrum Lord / Project Leader. You must boss everyone around and make daily reports
  to the professor of the progress made that day. You also will write up the
  final report which talks about your development process, write the README.md
  which will include the documentation of how to play the game. The README needs
  colors and images. Explain what each person did on the project, what their
  role was, and if they met their individual goals. (Mohamed Mohamed)

  Person 2: JJK Curse Lord. You must use either NCURSES or DearIMGUI to create a
  UI for your game (Michael Moran)

  Person 3: Spiderman/Spiderwoman (AKA The Thread Lord): you must use
  multithreading in an interesting way, such as handling IO in a separate thread
  from the main loop, so the game can run while you process input. You should
  use Mutexes and lock_guards

  Person 4: DJ Bridges (the artist formerly known as the BRIDGEngineer) you must
  make a soundtrack and sound effects for your game in BRIDGES. It's fine if the
  user has to open a web page and hit play themselves. You need to make original
  music and sound, not plagiarizing.(jose-possibly, if mutiplayer role is taken)

  Person 5: Inheritor of Suffering. You must make a class heirarchy of heroes
  and monsters and have a vector of shared_ptrs holding all the actors in the
  world. Every actor (the base class) should have a function variable for its
  AI. Every game tick, all the actors in the world should run their AI function.
  For human controlled actors, the AI function should just return, or you could
  have it process the input and move around that way. Your game should have
  monsters that wander around the map in real time

  Person 6: Socketroth. You must implement networking and either make the game
  multiplayer or have some other interesting use for networking. You should have a client/server model where the client will connect to a
  server and the server sends updates to the client.

  Person 7: Taste Tester / 50 Cent. You must write tests for the other people
  that are writing code using G Unit (Google Test Suite). Not all code is
  testable, such as UI code, but you can at least look at it and run some QA on
  it to make sure all the UI works.

  Person 8: Integration Specialization Amalgamation Decimation (ISAD). You must take
  the work all the other people do and make a usable game out of it. You are
  also responsible for generating a UML diagram showing how all the pieces fit
  together.

  Person 9: Screenwriter(This, this is Jerrick Wallace). Must come up with at least 40 lines of dialogue, 40 lines of environmental description, and a theme/story to the game.

Reports: 
Day 1: Confirmed theme of the game which is a prison break game. We got a finished a wire cutting  which the player will have to go through during the game. We also got a server and client .cc files made and so far it is able to connect with one another. General map was drawn out for the prison as well.

Day 2: The RPG UI and Map baseline was completed today. Also the characters for the game was added into a header file. We also set up a meeting for tomorrow in order to update each other and clarify any questions/ concerns if necessary. 

Day 3: Today, the Padlock puzzle got finished and works with ncurses. A guard class for the prison guards was created as well. A thread.h header was added. Also had a meeting to discuess the overall foundation/flow of the game. Some thoughts are: Prisoner riddle and using a lockpick.

Day 4: Server.cc file was worked on and forweard progress. Ideas like a car manual was discuessed. Also getting a code to use towards the finish of the game was talked about as well.

Day 5: Tic Tac Toe was started, which is one of the puzzles we will have in the game. 
