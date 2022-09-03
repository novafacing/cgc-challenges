#ifndef CGC_MATCH_OBJECTS
#define CGC_MATCH_OBJECTS
#include "cgc_myint.h"

#define MATCH_OBJECT_SIZE (7 * 12)
typedef struct match_object_t match_object_t;
struct match_object_t {
  u32 width, height;
  char character;
  u8 map[MATCH_OBJECT_SIZE];
};

#define NUM_MATCH_OBJECTS 27
match_object_t match_objects[NUM_MATCH_OBJECTS] = {
  {
    .character = 'a',
    .width = 7,
    .height = 12,
    .map = {
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','1','1','1','1','0','0',
      '0','0','0','0','0','1','0',
      '0','0','1','1','1','1','0',
      '0','1','0','0','0','1','0',
      '0','1','0','0','0','1','0',
      '0','0','1','1','1','0','1',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
    }
  },
  {
    .character = 'b',
    .width = 7,
    .height = 12,
    .map = {
      '1','1','0','0','0','0','0',
      '0','1','0','0','0','0','0',
      '0','1','0','0','0','0','0',
      '0','1','1','1','1','0','0',
      '0','1','0','0','0','1','0',
      '0','1','0','0','0','1','0',
      '0','1','0','0','0','1','0',
      '0','1','0','0','0','1','0',
      '1','0','1','1','1','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
    }
  },
  {
    .character = 'c',
    .width = 7,
    .height = 12,
    .map = {
      '0','1','1','1','1','0','0',
      '0','1','0','0','0','0','0',
      '0','1','0','0','0','0','0',
      '0','1','0','0','0','0','0',
      '0','1','0','0','0','0','0',
      '0','1','0','0','0','0','0',
      '0','1','0','0','0','0','0',
      '0','1','0','0','0','0','0',
      '0','1','0','0','0','0','0',
      '0','1','0','0','0','0','0',
      '0','1','1','1','1','0','0',
      '0','0','0','0','0','0','0',
    }
  },
  {
    .character = 'd',
    .width = 7,
    .height = 12,
    .map = {
      '0','0','0','0','1','1','0',
      '0','0','0','0','0','1','0',
      '0','0','0','0','0','1','0',
      '0','0','1','1','1','1','0',
      '0','1','0','0','0','1','0',
      '0','1','0','0','0','1','0',
      '0','1','0','0','0','1','0',
      '0','1','0','0','0','1','0',
      '0','0','1','1','1','0','1',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
    }
  },
  {
    .character = 'e',
    .width = 7,
    .height = 12,
    .map = {
        '0','0','0','0','0','0','0',
        '0','0','0','0','0','0','0',
        '0','1','1','1','1','1','0',
        '0','1','0','0','0','1','0',
        '0','1','0','0','0','1','0',
        '0','1','0','1','1','1','0',
        '0','1','0','0','0','0','0',
        '0','1','0','0','0','1','0',
        '0','0','1','1','1','0','0',
        '0','0','0','0','0','0','0',
        '0','0','0','0','0','0','0',
        '0','0','0','0','0','0','0',
    }
  },
  {
    .character = 'f',
    .width = 7,
    .height = 12,
    .map = {
      '0','0','1','1','1','1','0',
      '0','0','1','0','0','0','0',
      '0','0','1','0','0','0','0',
      '1','1','1','1','1','1','1',
      '0','0','1','0','0','0','0',
      '0','0','1','0','0','0','0',
      '0','0','1','0','0','0','0',
      '0','0','1','0','0','0','0',
      '0','1','1','1','1','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
    }
  },
  {
    .character = 'g',
    .width = 7,
    .height = 12,
    .map = {
      '0','0','0','0','0','0','0',
      '0','1','1','1','1','0','1',
      '0','1','0','0','0','0','0',
      '0','1','0','0','0','1','0',
      '0','1','0','0','0','1','0',
      '0','1','0','0','0','1','0',
      '0','1','0','0','0','1','0',
      '0','1','1','1','1','1','0',
      '0','0','0','0','0','1','0',
      '0','0','0','0','0','1','0',
      '0','0','0','0','0','1','0',
      '0','0','1','1','1','0','0',
    }
  },
  {
    .character = 'h',
    .width = 7,
    .height = 12,
    .map = {
      '1','1','0','0','0','0','0',
      '0','1','1','1','0','0','0',
      '0','1','0','0','1','0','0',
      '0','1','0','0','0','0','0',
      '0','1','0','0','0','1','0',
      '0','1','0','0','0','1','0',
      '0','1','0','0','0','1','0',
      '0','1','0','0','0','1','0',
      '1','1','1','0','1','1','1',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
    }
  },
  {
    .character = 'i',
    .width = 7,
    .height = 12,
    .map = {
      '0','0','0','1','0','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','1','1','1','0','0','0',
      '0','0','0','1','0','0','0',
      '0','0','0','1','0','0','0',
      '0','0','0','1','0','0','0',
      '0','0','0','1','0','0','0',
      '0','1','1','1','1','1','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
    }
  },
  {
    .character = 'j',
    .width = 7,
    .height = 12,
    .map = {
      '0','0','0','0','1','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','1','1','1','1','0','0',
      '0','0','0','0','1','0','0',
      '0','0','0','0','1','0','0',
      '0','0','0','0','1','0','0',
      '0','0','0','0','1','0','0',
      '0','0','0','0','1','0','0',
      '0','0','0','0','1','0','0',
      '0','0','0','0','1','0','0',
      '0','1','1','1','0','0','0',
    }
  },
  {
    .character = 'k',
    .width = 7,
    .height = 12,
    .map = {
      '1','1','0','0','0','0','0',
      '0','1','0','0','0','0','0',
      '0','1','0','0','0','0','0',
      '0','1','0','0','1','1','0',
      '0','1','0','1','0','0','0',
      '0','1','1','0','0','0','0',
      '0','1','0','1','0','0','0',
      '0','1','0','0','1','0','0',
      '1','1','0','0','0','1','1',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
    }
  },
  {
    .character = 'l',
    .width = 7,
    .height = 12,
    .map = {
      '0','1','1','1','0','0','0',
      '0','0','0','1','0','0','0',
      '0','0','0','1','0','0','0',
      '0','0','0','1','0','0','0',
      '0','0','0','1','0','0','0',
      '0','0','0','1','0','0','0',
      '0','0','0','1','0','0','0',
      '0','0','0','1','0','0','0',
      '0','1','1','1','1','1','1',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
    }
  },
  {
    .character = 'm',
    .width = 7,
    .height = 12,
    .map = {
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '1','1','1','0','1','0','0',
      '0','1','0','1','0','1','0',
      '0','1','0','1','0','1','0',
      '0','1','0','1','0','1','0',
      '0','1','0','1','0','1','0',
      '1','1','0','1','0','1','1',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
    }
  },
  {
    .character = 'n',
    .width = 7,
    .height = 12,
    .map = {
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '1','0','1','1','1','0','0',
      '0','1','1','0','0','1','0',
      '0','1','0','0','0','1','0',
      '0','1','0','0','0','1','0',
      '0','1','0','0','0','1','0',
      '1','1','1','0','0','1','1',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
    }
  },
  {
    .character = 'o',
    .width = 7,
    .height = 12,
    .map = {
      '0','0','0','0','0','0','0',
      '0','1','1','1','1','1','0',
      '0','1','0','0','0','1','0',
      '0','1','0','0','0','1','0',
      '0','1','0','0','0','1','0',
      '0','1','0','1','0','1','0',
      '0','1','0','1','0','1','0',
      '0','1','0','1','0','1','0',
      '0','1','0','0','0','1','0',
      '0','1','0','0','0','1','0',
      '0','1','1','1','1','1','0',
      '0','0','0','0','0','0','0',
    }
  },
  {
    .character = 'p',
    .width = 7,
    .height = 12,
    .map = {
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '1','0','1','1','1','0','0',
      '0','1','0','0','0','1','0',
      '0','1','0','0','0','1','0',
      '0','1','0','0','0','1','0',
      '0','1','0','0','0','1','0',
      '0','1','1','1','1','0','0',
      '0','1','0','0','0','0','0',
      '0','1','0','0','0','0','0',
      '1','1','1','0','0','0','0',
    }
  },
  {
    .character = 'q',
    .width = 7,
    .height = 12,
    .map = {
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','0','1','1','1','0','1',
      '0','1','0','0','0','1','0',
      '0','1','0','0','0','1','0',
      '0','1','0','0','0','1','0',
      '0','1','0','0','0','1','0',
      '0','0','1','1','1','1','0',
      '0','0','0','0','0','1','0',
      '0','0','0','0','0','1','0',
      '0','0','0','0','1','1','1',
    }
  },
  {
    .character = 'r',
    .width = 7,
    .height = 12,
    .map = {
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','1','0','1','1','1','0',
      '0','0','1','0','0','0','0',
      '0','0','1','0','0','0','0',
      '0','0','1','0','0','0','0',
      '0','0','1','0','0','0','0',
      '0','1','1','1','1','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
    }
  },
  {
    .character = 's',
    .width = 7,
    .height = 12,
    .map = {
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','0','1','1','1','0','0',
      '0','1','0','0','0','1','0',
      '0','0','1','1','1','0','0',
      '0','0','0','0','0','1','0',
      '0','1','0','0','0','1','0',
      '0','0','1','1','1','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
    }
  },
  {
    .character = 't',
    .width = 7,
    .height = 12,
    .map = {
      '0','0','0','0','0','0','0',
      '0','0','1','0','0','0','0',
      '0','0','1','0','0','0','0',
      '0','1','1','1','1','1','0',
      '0','0','1','0','0','0','0',
      '0','0','1','0','0','0','0',
      '0','0','1','0','0','0','0',
      '0','0','1','0','0','0','1',
      '0','0','0','1','1','1','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
    }
  },
  {
    .character = 'u',
    .width = 7,
    .height = 12,
    .map = {
      '0','0','0','0','0','0','0',
      '0','0','0','0','1','1','0',
      '0','0','0','0','0','1','0',
      '1','1','0','0','0','1','0',
      '1','1','0','0','0','1','0',
      '1','1','0','0','0','1','0',
      '0','1','0','0','0','1','0',
      '0','1','0','0','0','1','0',
      '0','0','1','1','1','0','1',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
    }
  },
  {
    .character = 'v',
    .width = 7,
    .height = 12,
    .map = {
      '0','0','0','0','0','0','0',
      '1','1','1','0','1','1','1',
      '0','1','0','0','0','1','0',
      '0','1','0','0','0','1','0',
      '0','1','0','0','0','1','0',
      '0','1','0','0','0','1','0',
      '0','1','0','0','0','1','0',
      '0','1','0','0','0','1','0',
      '0','0','1','0','1','0','0',
      '0','0','0','1','0','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
    }
  },
  {
    .character = 'w',
    .width = 7,
    .height = 12,
    .map = {
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '1','1','1','0','1','1','1',
      '0','1','0','0','0','1','0',
      '0','1','0','1','0','1','0',
      '0','1','0','1','0','1','0',
      '0','0','1','0','1','0','0',
      '0','0','1','0','1','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
    }
  },
  {
    .character = 'x',
    .width = 7,
    .height = 12,
    .map = {
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '1','1','1','0','1','1','1',
      '0','0','1','0','1','0','0',
      '0','0','0','1','0','0','0',
      '0','0','1','0','1','0','0',
      '0','1','0','0','0','1','0',
      '1','1','0','0','0','1','1',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
    }
  },
  {
    .character = 'y',
    .width = 7,
    .height = 12,
    .map = {
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '1','1','1','0','1','1','1',
      '0','1','0','0','0','1','0',
      '0','1','0','0','0','1','0',
      '0','0','1','0','1','0','0',
      '0','0','1','1','1','0','0',
      '0','0','0','1','0','0','0',
      '0','0','0','1','0','0','0',
      '0','0','0','1','0','0','0',
      '0','1','1','0','0','0','0',
    }
  },
  {
    .character = 'z',
    .width = 7,
    .height = 12,
    .map = {
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','1','1','1','1','1','0',
      '0','1','0','0','1','0','0',
      '0','0','0','1','0','0','0',
      '0','0','1','0','0','0','0',
      '0','1','0','0','0','1','0',
      '0','1','1','1','1','1','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
    }
  },
  {
    .character = ' ',
    .width = 7,
    .height = 12,
    .map = {
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
      '0','0','0','0','0','0','0',
    }
  }
};

#endif // CGC_MATCH_OBJECTS