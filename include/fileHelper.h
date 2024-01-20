#ifndef NOTE_FILEHELPER_H
#define NOTE_FILEHELPER_H

typedef struct{
    float x, y, z, yaw, pitch, roll;

}NOTE_camera;

const char* loadFile(const char* filename);
void saveFile(const char* filename, const char* data);
#endif