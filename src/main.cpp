#include <allegro.h>
#include <time.h>

// Variables
const int numberKittens = 16;

int angle = 40;

int initMouseX;
int initMouseY;

bool closeScreenSaver = false;

BITMAP* buffer;

// Cat class
struct cats{
  BITMAP* image;
  int size;
  int x;
  int y;
}catMob[numberKittens];

// Generate number
int random(int newLowest, int newHighest){
  int lowest = newLowest, highest = newHighest;
  int range = (highest - lowest) + 1;
  int randomNumber = lowest+int(range*rand()/(RAND_MAX + 1.0));
  return randomNumber;
}

// Setup cats
void setup(){
  srand(time(NULL));

  // Make nice buffer
  buffer = create_bitmap( SCREEN_W, SCREEN_H);

  // Load kittens
  for(int i = 0; i < numberKittens; i++){
    catMob[i].x = random( 0,SCREEN_W);
    catMob[i].y = random( 0,SCREEN_H);

    int randomInt = random(0,8);

    if( randomInt == 0){
      catMob[i].image = load_bitmap( "cat1.bmp", NULL);
    }
    else if(randomInt == 1){
      catMob[i].image = load_bitmap( "cat2.bmp", NULL);
    }
    else if(randomInt == 2){
      catMob[i].image = load_bitmap( "cat3.bmp", NULL);
    }
    else if(randomInt == 3){
      catMob[i].image = load_bitmap( "cat4.bmp", NULL);
    }
    else if(randomInt == 4){
      catMob[i].image = load_bitmap( "cat5.bmp", NULL);
    }
    else if(randomInt == 5){
      catMob[i].image = load_bitmap( "cat6.bmp", NULL);
    }
    else if(randomInt == 6){
      catMob[i].image = load_bitmap( "cat7.bmp", NULL);
    }
    else if(randomInt == 7){
      catMob[i].image = load_bitmap( "cat8.bmp", NULL);
    }
    else{
      catMob[i].image = load_bitmap( "cat10.bmp", NULL);
    }
  }
}

// Loop
void loop(){
  // Mouse moved?
  int initMouseX = mouse_x;
  int initMouseY = mouse_y;

  // Draw loop
  for( int i = 0; i < numberKittens; i++){
    catMob[i].x = random(0,SCREEN_W);
    catMob[i].y = random(0,SCREEN_H);
    rotate_scaled_sprite(buffer,catMob[i].image,catMob[i].x,catMob[i].y, itofix(random(-angle,angle)), itofix(random(1,2)));
  }

  // Buffer
  draw_sprite(screen,buffer,0,0);

  // Wait a bit
  rest(100);

  // Mouse moved
  if( abs(mouse_x - initMouseX) > 10  || abs(mouse_y - initMouseY) > 10 || key[KEY_ESC]){
    closeScreenSaver = true;
  }
}

int main(){
  // Install allegro
  allegro_init();
  //alpng_init();
  install_timer();
  install_keyboard();
  install_mouse();
  set_color_depth(32);

  // Init screen
  int w, h;
  get_desktop_resolution( &w, &h);
  set_gfx_mode( GFX_AUTODETECT_FULLSCREEN, w, h, 0, 0);

  set_window_title( "Cuteness Overload!");

  // Setup game
  setup();

  // Loop until exit
  while( !closeScreenSaver){
    loop();
  }
}
END_OF_MAIN();
