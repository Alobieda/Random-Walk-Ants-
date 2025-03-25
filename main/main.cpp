// // #include "nlohmann/json.hpp"
// // #include <cadmium/modeling/celldevs/grid/coupled.hpp>
// // #include <cadmium/simulation/logger/csv.hpp>
// // #include <cadmium/simulation/root_coordinator.hpp>
// // #include <chrono>
// // #include <fstream>
// // #include <string>

// // // Include your walk/ants headers (replace with your actual file names/paths)
// // #include "include/walk_cell_state.hpp"
// // #include "include/walk_factory.hpp"

// // using namespace cadmium::celldevs;
// // using namespace cadmium;

// // int main(int argc, char ** argv) {
// //     if (argc < 2) {
// //         std::cout << "Program used with wrong parameters.\n";
// //         std::cout << "Usage: " << argv[0] << " SCENARIO_CONFIG.json [MAX_SIMULATION_TIME=500]\n";
// //         return -1;
// //     }

// //     std::string configFilePath = argv[1];
// //     double simTime = (argc > 2) ? std::stod(argv[2]) : 500.0;

// // 	std::cout << "Loading scenario file: " << configFilePath << std::endl;

// //     // Create the top-level cell model using your 'WalkCellState' and 'walkFactory'
// //     auto model = std::make_shared<GridCellDEVSCoupled<WalkCellState, double>>(
// //         "walk",        // model name for logging
// //         walkFactory,   // factory function
// //         configFilePath // path to your JSON scenario
// //     );
// //     //auto model = std::make_shared<GridCellDEVSCoupled<fireAndRainState, double>>("fireAndRain", addGridCell, configFilePath);
    
// //     model->buildModel();
    
// //     // Set up a root coordinator
// //     auto rootCoordinator = RootCoordinator(model);
// //     rootCoordinator.setLogger<CSVLogger>("walk_log.csv", ";");
    
// //     // Run the simulation
// //     rootCoordinator.start();
// //     rootCoordinator.simulate(simTime);
// //     rootCoordinator.stop();

// //     std::cout << "Simulation finished. Check walk_log.csv for output.\n";
// //     return 0;
// // }


// #include "nlohmann/json.hpp"
// #include <cadmium/modeling/celldevs/grid/coupled.hpp>
// #include <cadmium/simulation/logger/csv.hpp>
// #include <cadmium/simulation/root_coordinator.hpp>
// #include <chrono>
// #include <fstream>
// #include <string>
// //#include "include/walk_cell_state.hpp"
#include "walk_cell.hpp"

// using namespace cadmium::celldevs;
// using namespace cadmium;

// std::shared_ptr<GridCell<WalkCellState, double>> addGridCell(const coordinates & cellId, const std::shared_ptr<const GridCellConfig<WalkCellState, double>>& cellConfig) {
//     auto cellModel = cellConfig->cellModel;

//     if (cellModel == "WalkCell") {
//         return std::make_shared<WalkCell>(cellId, cellConfig);
//     } else {
//         throw std::bad_typeid();
//     }
// }

// int main(int argc, char ** argv) {
//     if (argc < 2) {
//         std::cout << "Program used with wrong parameters. The program must be invoked as follows:";
//         std::cout << argv[0] << " SCENARIO_CONFIG.json [MAX_SIMULATION_TIME (default: 500)]" << std::endl;
//         return -1;
//     }
//     std::string configFilePath = argv[1];
//     double simTime = (argc > 2)? std::stod(argv[2]) : 500;

//     auto model = std::make_shared<GridCellDEVSCoupled<WalkCellState, double>>("walk", addGridCell, configFilePath);
//     model->buildModel();

//     auto rootCoordinator = RootCoordinator(model);
//     rootCoordinator.setLogger<CSVLogger>("walk_log.csv", ";");

//     //auto rootCoordinator = RootCoordinator(model);
//     //rootCoordinator.setLogger<CSVLogger>("walk_log.csv", ";");

//     rootCoordinator.start();
//     rootCoordinator.simulate(simTime);
//     rootCoordinator.stop();
// }


#include "nlohmann/json.hpp"
#include <cadmium/modeling/celldevs/grid/coupled.hpp>
#include <cadmium/simulation/logger/csv.hpp>
#include <cadmium/simulation/root_coordinator.hpp>
#include <chrono>
#include <fstream>
#include <string>

// Include your updated files (adjust paths if necessary):
// #include "walkCellState.hpp"
#include "walk_factory.hpp"

using namespace cadmium::celldevs;
using namespace cadmium;

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Program used with wrong parameters.\n";
        std::cout << "Usage: " << argv[0] << " SCENARIO_CONFIG.json [MAX_SIMULATION_TIME=500]\n";
        return -1;
    }

    std::string configFilePath = argv[1];
    double simTime = (argc > 2) ? std::stod(argv[2]) : 500.0;

    std::cout << "Loading scenario file: " << configFilePath << std::endl;

    // Create the top-level cell model using your 'walkCellState' and 'walkcellFactory'.
    auto model = std::make_shared<GridCellDEVSCoupled<walkCellState, double>>(
        "walk",              // model name for logging
        walkcellFactory,     // factory function
        configFilePath       // path to your JSON scenario
    );
    model->buildModel();

    // Set up a root coordinator
    auto rootCoordinator = RootCoordinator(model);
    rootCoordinator.setLogger<CSVLogger>("walk_log.csv", ";");

    // Run the simulation
    rootCoordinator.start();
    rootCoordinator.simulate(simTime);
    rootCoordinator.stop();

    std::cout << "Simulation finished. Check walk_log.csv for output.\n";
    return 0;
}
