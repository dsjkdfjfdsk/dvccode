#ifndef MUSIC_H
#define MUSIC_H
#include <string> 
using namespace std;

//Music class with duration and format members. Derived from Publication class
class Music : public Publication
{
    private:
        int duration;
        string format;
    public:
        Music ()
        {}
        Music (int musicDuration, string musicFormat)
        {
            duration = musicDuration;
            format = musicFormat;
        }
        void setDuration(int musicDuration)
        {
            duration = musicDuration;
        }
        void setFormat(string musicFormat)
        {
            format = musicFormat;
        }
        string getFormat()
        {
            return format;
        }
        int  getDuration()
        {
            return duration;
        }
};

#endif