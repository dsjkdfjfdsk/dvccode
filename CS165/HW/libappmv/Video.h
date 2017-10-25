#ifndef VIDEO_H
#define VIDEO_H
#include <string> 
using namespace std;

class Video : public Publication
{
    private:
        string resolution;
        string producer;
    public:
        Video ()
        {}
        Video (int videoResolution, string videoProducer)
        {
            resolution = videoResolution;
            producer = videoProducer;
        }
        void setResolution(int videoResolution)
        {
            resolution = videoResolution;
        }
        void setProducer(string videoProducer)
        {
            producer = videoProducer;
        }
        string getResolution()
        {
            return resolution;
        }
        string  getProducer()
        {
            return producer;
        }
};
#endif