
// ofxDSHapVideoPlayer written by Jeremy Rotsztain and Philippe Laurheret for Second Story, 2015
// DirectShowVideo and ofDirectShowPlayer written by Theodore Watson, Jan 2014
// See the cpp file for the DirectShow implementation 
// Forked to https://github.com/acheson/ofxDSHapVideoPlayer
// Edited to support selection of audio output destination

#pragma once 

#include "ofMain.h"
#include "HapShared.h"

class DirectShowHapVideo;

class ofxDSHapVideoPlayer : public ofBaseVideoPlayer {

	public:

		ofxDSHapVideoPlayer();
		~ofxDSHapVideoPlayer();

		bool load(string path); 
		bool load(string path, int audioDeviceIndex);
		void update();
		void waitUpdate(long milliseconds);
		void writeToTexture(ofTexture& texture);
		void draw(int x, int y, int w, int h, int alpha);
		void draw(int x, int y, int alpha = 255) { draw(x, y, getWidth(), getHeight(), alpha); }

		 void				close();
	
		 void				play();
		 void				pause();
		 void				stop();		
	
		 bool 				isFrameNew() const ;
		 ofPixels &		 	getPixels(); // @NOTE: return uncompressed pixels
		 const ofPixels &    getPixels() const;
	     //unsigned char *	getPixels();
	
		 float 				getWidth() const;
		 float 				getHeight() const;
	
		 bool				isPaused() const;
		 bool				isLoaded() const;
		 bool				isPlaying() const;
	
		 bool setPixelFormat(ofPixelFormat pixelFormat);
		 ofPixelFormat 		getPixelFormat() const;
         ofShader           getShader();
         ofTexture *        getTexture();

		 float 				getPosition();
		 float 				getSpeed();
		 float 				getDuration();
		 bool				getIsMovieDone();
	
		 void 				setPaused(bool bPause);
		 void 				setPosition(float pct);
		 void 				setVolume(float volume); // 0..1
		 void 				setLoopState(ofLoopType state);
		 void   			setSpeed(float speed);
		 void				setFrame(int frame);  // frame 0 = first frame...

		 int				getCurrentFrame() const;
		 int				getTotalFrames() const;
		 ofLoopType			getLoopState() const;
	
		 void				firstFrame();
		 void				nextFrame();
		 void				previousFrame();

         enum               HapType {
                                HAP,
                                HAPALPHA,
                                HAPQ
                            };

         HapType            getHapType();

		 int				height;
		 int				width;
		 
		 string		deviceName;
		 int		device;

	protected:

		// using DS for grabbing frames
		DirectShowHapVideo * player;
		
		// hap shader (for YCoCg)
		ofShader shader; 
		bool bShaderInitialized;

		ofPixels pix; // copy of compressed pixels
		ofTexture tex; // texture for pix

		HapTextureFormat textureFormat;

		//void printAudioEndpointNames();
		//void setAudioEndpoint(int index);
		//void connectAudio();

		

};
