//
//  Jetclustering_example.cpp
//  
//
//  Created by Yasmin Sarhan on 4/2/24.
//
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include "fastjet/ClusterSequence.hh"

using namespace std;
using namespace fastjet;

vector<PseudoJet> generate_particles(int num_particles) {
    vector<PseudoJet> particles;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis_px(-100.0, 100.0);
    uniform_real_distribution<> dis_py(-0.1, 0.1);
    uniform_real_distribution<> dis_energy(50.0, 150.0);

    for (int i = 0; i < num_particles; ++i) {
        double px = dis_px(gen);
        double py = dis_py(gen);
        double pz = 0.0; // Assuming particles are in the transverse plane
        double energy = dis_energy(gen);
        particles.push_back(PseudoJet(px, py, pz, energy));
    }
    return particles;
}

double run_jet_clustering(int num_particles) {
    // Generate particles
    vector<PseudoJet> particles = generate_particles(num_particles);

    // Choose a jet definition
    double R = 0.7;
    JetDefinition jet_def(antikt_algorithm, R);

    // Record start time
    auto start_time = chrono::high_resolution_clock::now();

// Run clustering, extract jets
    ClusterSequence cs(particles, jet_def);
    vector<PseudoJet> jets = sorted_by_pt(cs.inclusive_jets());

    // Record end time
    auto end_time = chrono::high_resolution_clock::now();

    // Calculate runtime
    chrono::duration<double> runtime = end_time - start_time;

    // Print out some info
    cout << "Clustered with " << jet_def.description() << endl;

    // Print the jets
    cout << "        pt y phi" << endl;
    for (unsigned i = 0; i < jets.size(); ++i) {
        cout << "jet " << i << ": " << jets[i].pt() << " " << jets[i].rap() << " " << jets[i].phi() << endl;
        vector<PseudoJet> constituents = jets[i].constituents();
        for (unsigned j = 0; j < constituents.size(); ++j) {
            cout << "    constituent " << j << "'s pt: " << constituents[j].pt() << endl;
        }
    }

    // Return runtime
    return runtime.count();
}

int main() {
    int num_particles = 100; // Change this number to specify the number of particles
    double runtime = run_jet_clustering(num_particles);
    cout << "Runtime: " << runtime << " seconds" << endl;
    return 0;
}
