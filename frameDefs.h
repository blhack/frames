struct Pixel {
  short index;
  short R;
  short G;
  short B;
};

struct Frame {
  Pixel pixels[10];
  unsigned long expiration;
};

Frame frames1[10] = {
                      {
                        {{0,255,255,255},{1,255,255,255},{2,255,255,255},{3,255,255,255}},
                        1000
                      },
                      {
                        {{0, 255,255,255},{1,255,255,255},{2,255,255,255},{3,255,255,255}},
                        500
                      }
                    };

void loadFrames() {
  //
}
