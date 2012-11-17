//
//  ForceSpin.h
//
//  Created by Jim on 9/28/12.
//
//

#pragma once

#include "Force.h"
class ForceSpin : public Force {
public:
    
    ofVec3f center;
	float power;
    float explodePower;
	float explodeVar;
	float zWind;
    ForceSpin() {
        power = .0;
		explodePower = 0.;
		explodeVar = 0;
		zWind = 0;
    }
    
    void update(){

    }
    
    void applyForce(vector<Particle>& particles){
        //currentOffset = 0;
        for(int i = 0; i < particles.size(); i++){
            ofVec3f& pos = particles[i].position;
			ofVec3f directionFromCenter = (pos-center).getNormalized();
			particles[i].force += directionFromCenter.getRotated(90, ofVec3f(0,1,0)) *ofVec3f(1,0,1) * power;
//				directionFromCenter += ofVec3f(ofRandom(-.1,.1),ofRandom(-.1,.1),ofRandom(-.1,.1));
			directionFromCenter += ofVec3f(ofRandom(-1,1),ofRandom(-1,1),ofRandom(-1,1));
			directionFromCenter.normalize();
			particles[i].force += directionFromCenter * (explodePower + ofRandom(explodeVar*explodePower));
			//particles[i].force += ofVec3f(zWind*ofSignedNoise(pos.x/1000.)/100.,zWind*ofSignedNoise(pos.x/1000.)/100.,0,zWind);
			particles[i].force += ofVec3f(0,0,zWind);
        }
    }
};

