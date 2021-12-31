#include "ofApp.h"

#define quantity 50
		

int p_rad_min = 20;
int p_rad_max = 5;

Particle particlegroup1[quantity];

vector <Trail> trails;
/// My Functions////
int num_t_grp;
int frame;
void p2p_collision(Particle particlegroup[quantity]) {

	int particle_group_size = quantity;

	for (int i = 0; i < particle_group_size; i++) {
		for (int j = 0; j < particle_group_size; j++) {
			
			// Ball 2 ball collision 
			ofVec2f i_pos(particlegroup[i].get_pos()); //get pos of first particle
			ofVec2f j_pos(particlegroup[j].get_pos()); // get pois of second particle
			int i_rad = particlegroup[i].get_p_rad(); // get rads
			int j_rad = particlegroup[j].get_p_rad();

			float force_modifier = 0.25;

			float distance_between = i_pos.distance(j_pos); //using ofvec.distance (slow) to get the distance between balls
			float touching_distance = i_rad + j_rad; // setting which distance is touching

			if (distance_between <= touching_distance) { // if particles touch

				int particle_i2j_dx = particlegroup[i].get_pos().x - particlegroup[j].get_pos().x; //difference in x between particles
				int particle_i2j_dy = particlegroup[i].get_pos().y - particlegroup[j].get_pos().y; //difference in y

				ofVec2f react_vector_i(particle_i2j_dx, particle_i2j_dy);
				ofVec2f react_force_i = react_vector_i * force_modifier * 1 / i_rad; //add size adjusted force

				int particle_j2i_dx = particlegroup[j].get_pos().x - particlegroup[i].get_pos().x;
				int particle_j2i_dy = particlegroup[j].get_pos().y - particlegroup[i].get_pos().y;

				ofVec2f react_vector_j(particle_j2i_dx, particle_j2i_dy);
				ofVec2f react_force_j = react_vector_j * force_modifier * 1 / j_rad;//add size adjusted force

				particlegroup[i].add_force(react_force_i);
				particlegroup[j].add_force(react_force_j);

				
			}
			
		}
		particlegroup[i].update();
		
	}
}



//--------------------------------------------------------------
void ofApp::setup(){
	
	//ofSetFrameRate(60);
	

	for (int i = 0; i < quantity; i++) {

		int rand_x = ofRandom(50, 200);
		int rand_y = ofRandom(50, 200);
		int particle_size = ofRandom(p_rad_min, p_rad_max);
		ofVec2f pos(rand_x, rand_y);
		particlegroup1[i].setup(rand_x,rand_y,particle_size);
		Trail trail(pos, particle_size);
		trails.push_back(trail);
	}

}


//--------------------------------------------------------------
void ofApp::update() {

	p2p_collision(particlegroup1);
	
	

	for (int i = 0; i < quantity; i++) { 

		ofVec2f parti_pos = particlegroup1[i].get_pos(); // getting particle information
		int parti_rad = particlegroup1[i].get_p_rad();

		for (int j = 0; j < trails.size(); j++) {

			trails[j].update(parti_pos);

		}
	
	}

}


//--------------------------------------------------------------
void ofApp::draw(){
	
	
	//particle.debug();
	
	for (int i = 0; i < quantity; i++) {

		particlegroup1[i].draw();
		
	}

	for (int i = 0; i < trails.size(); i++) {

		trails[i].draw();

		}


	//debug
	int num_trail_pt = trails[1].get_positions().size();
	ofDrawBitmapString(num_trail_pt, 5, 15);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){


}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

