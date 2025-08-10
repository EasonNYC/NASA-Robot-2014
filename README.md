R# NYU Team Atlas - NASA Lunar Mining Robot 2014

[![NASA Competition](https://img.shields.io/badge/NASA-Robotic%20Mining%20Competition-blue.svg)](http://www.nasa.gov/offices/education/centers/kennedy/technology/nasarmc.html)
[![Arduino](https://img.shields.io/badge/Arduino-Mega-blue.svg)](https://www.arduino.cc/en/Main/ArduinoBoardMega)
[![LabVIEW](https://img.shields.io/badge/LabVIEW-Control%20System-orange.svg)](https://www.ni.com/labview/)

**NYU's Atlas 4 Autonomous Lunar Mining Robot for the 2014 NASA Robotic Mining Competition at Kennedy Space Center**

![Team Atlas Robot](https://img.shields.io/badge/Weight-26kg-green.svg)
![Award](https://img.shields.io/badge/Achievement-Innovation%20Award-gold.svg)

## 🏆 Competition Overview

The NASA Robotic Mining Competition challenges university teams to design and build a robot capable of traversing simulated Martian terrain, excavating lunar regolith simulant (BP-1), and depositing it into a collection bin within 10 minutes. Our robot, **Atlas 4**, was specifically designed to operate in reduced 1/3 gravity and handle the abrasive characteristics of basaltic regolith.

### 🎯 Mission Objectives
- Navigate complex obstacle-laden terrain telerobotically 
- Mine and collect lunar regolith simulant (BP-1)
- Transport and deposit regolith into designated collection areas
- Operate reliably in dusty, hazardous environments
- Minimize mass while maximizing collection efficiency

## 🤖 Robot Design Philosophy

**Atlas 4** represents a revolutionary approach to lunar mining with several breakthrough innovations:

### Key Innovations
- **Ultralight Design**: At only 26kg, one of the lightest robots in competition history
- **Wheel-Based Mining**: Unique excavation system using the drive wheels themselves as digging implements
- **3D Printed Construction**: Extensive use of additive manufacturing (80%+ of components)
- **Modular 3D Design**: Wheels printed in 6 interlocking pieces to overcome size constraints

### Design Principles
1. **Low Mass** - Carbon fiber frame and 3D printed components
2. **High Reliability** - Redundant systems and fail-safe mechanisms  
3. **Innovative Construction** - Novel solutions to manufacturing constraints
4. **Operational Safety** - Comprehensive monitoring and emergency protocols

## 🛠️ Technical Architecture

### Mechanical Systems
- **Frame**: Carbon fiber tube construction with 3D printed joint connectors
- **Wheels**: Six-piece interlocking 3D printed design with integrated scoops
- **Drivetrain**: Direct-drive motors with integrated gearboxes (325 in-lbs torque)
- **Collection System**: Central hopper with conveyor belt dumping mechanism
- **Actuators**: Linear actuators for hopper positioning and dumping

### Electronic Systems
- **Main Controller**: Arduino Mega (ATmega32u4)
- **Motor Control**: Sabertooth motor controllers with regenerative braking
- **Communication**: WiFi wireless link with watchdog timer and auto-reconnect
- **Power**: Dual 22.2V Lithium-Ion batteries in parallel configuration
- **Sensors**: Current monitoring, voltage sensing, optical encoders
- **Safety**: Emergency stop, power sequencing, thermal protection

### Software Architecture
- **Robot Firmware**: Arduino C/C++ with real-time sensor processing
- **Control Interface**: LabVIEW virtual instrument panel
- **Communication Protocol**: Custom packet-based protocol with error checking
- **Safety Systems**: Watchdog timer, heartbeat monitoring, auto-reconnect

## 🎮 Control System

### Ground Station Setup
- **Platform**: LabVIEW virtual instrument running on laptop
- **Input**: Xbox 360 controller for intuitive operation
- **Display**: Real-time telemetry including power, motor status, and video feed
- **Range**: 50-yard wireless communication range
- **Safety**: Automatic robot shutdown on communication loss

### Telemetry Systems
- Battery voltage and current monitoring
- Individual wheel speed feedback
- Linear actuator position sensing
- Motor stall detection
- Real-time alarm system with Apollo-inspired error codes

## 🔧 Unique Technical Features

### 3D Printed Wheel System
Our most innovative feature was the completely 3D printed wheel system:
- **Puzzle Design**: Each wheel comprised 6 interlocking pieces
- **Integrated Mining**: Fins with openings collect regolith during reverse rotation
- **Material Flow**: Regolith flows through wheel interior to central collection bin
- **Scalability**: Overcame 3D printer size limitations through modular design

### Advanced Communication Protocol
- **Robust Wireless**: WiFi with automatic failover and reconnection
- **Error Detection**: Checksums and sequence numbers prevent data corruption
- **Minimal Bandwidth**: Compact message format reduces communication overhead
- **Apollo Heritage**: Alarm code numbering system inspired by lunar module protocols

### Safety and Reliability Systems
- **Watchdog Timer**: 500ms timeout triggers safe mode if communication lost
- **Emergency Stop**: Physical and wireless emergency shutdown capabilities
- **Power Management**: Voltage regulation, current limiting, and thermal protection
- **Redundant Systems**: Multiple backup systems for critical functions

## 🔌 Hardware Requirements

### Electronics
- Arduino Mega 2560
- Sabertooth 2x32 Motor Controllers (2x)
- Sabertooth 1x32 Motor Controller (1x)
- WiFi Module (Roving Networks)
- Current Sensors (30A rating)
- Optical Encoders
- Linear Actuators (2x)
- 22.2V LiPo Batteries (2x)

### Mechanical
- Carbon Fiber Tubes and Connectors
- 3D Printed Components (PLA/ABS)
- DC Motors with Integrated Gearboxes (325 in-lbs)
- Aluminum Gusset Plates
- Hardware and Fasteners

## 🚀 Getting Started

### Prerequisites
- Arduino IDE 1.6.x or later
- LabVIEW 2014 or compatible version
- Xbox 360 Controller
- WiFi-capable laptop

### Arduino Setup
1. Clone this repository
2. Open `Robot.ino` in Arduino IDE
3. Install required libraries:
   - SoftwareSerial (for motor control)
   - WiFi library (for communication)
4. Upload to Arduino Mega
5. Connect hardware according to schematics

### LabVIEW Control Station
1. Open LabVIEW project files in `/labview/` directory
2. Configure WiFi network settings
3. Connect Xbox 360 controller
4. Run main control panel VI
5. Establish connection with robot

### Competition Operation
1. Power on robot and wait for initialization (30 seconds)
2. Establish wireless connection
3. Perform pre-run systems check
4. Navigate to mining area using telerobotic control
5. Engage wheel-based mining system
6. Transport regolith to collection area
7. Execute dumping sequence

### Team Leadership
As **Captain and Project Manager**, I led a diverse team of 13 undergraduate and graduate students across multiple engineering disciplines:
- 7 team members spanning ME, EE, CS, Physics, and Mathematics
- Year-long project timeline from concept to competition
- $3,500 budget management and resource allocation
- Cross-functional collaboration and integration

### Technical Contributions
- Electrical system architecture and implementation
- Communication protocol design and safety systems
- Software integration between Arduino and LabVIEW
- Project scheduling, risk assessment, and systems engineering

## 🧑‍💻 Software Technical Details

### Arduino Firmware Features
- **Multi-threaded Operation**: Concurrent sensor reading and motor control
- **Real-time Communication**: Packet-based protocol with error correction
- **Safety Monitoring**: Continuous system health checks and fault detection
- **Sensor Integration**: Current monitoring, encoders, and position feedback
- **Motor Control**: Coordinated 5-motor system with individual speed control

### LabVIEW Control Interface
- **Operator Dashboard**: Real-time robot status and telemetry display
- **Xbox Integration**: Natural controller interface for robot operation
- **Data Logging**: Complete mission data recording and analysis
- **Alarm System**: Visual and audible alerts for system anomalies
- **Communication Management**: Robust wireless protocol with auto-recovery

## 🎥 Media and Documentation

### Media Footage
- [NASA TV Interview](https://www.youtube.com/watch?v=hwmHyKBF8kE) - Post-competition interview at Kennedy Space Center
- [Robot Demo Video](link) - Indoor mobility and teleop demonstration
- [Competition Run](link) - Official mining competition footage

### Publications
- **NYU Engineering Website** - [Featured Article](https://engineering.nyu.edu/news/sophomores-take-upper-classes-nasa-lunar-robot-competition)
- **Systems Engineering Report** - Comprehensive technical documentation
- **NYU School Newspaper** - Competition preview and team profile

### Team Recognition
> *"Team Atlas has shifted its strategy toward 'building for the future,' focusing on recruiting the fresh talent of its underclassmen. This year's team consists entirely of sophomores, making Team Atlas one of the youngest teams who will compete at the NASA competition where teams made up of Seniors and Grad students is the norm."*

## 🔬 Engineering Impact

### Novel Manufacturing Approach
Our extensive use of 3D printing was groundbreaking for 2014:
- **80%+ 3D Printed Components** - Pioneered additive manufacturing in robotics competition
- **Puzzle-Piece Assembly** - Innovative solution to printer size limitations  
- **Rapid Prototyping** - Enabled quick iteration and design refinement
- **Weight Optimization** - Achieved significant mass reduction vs. traditional materials

### Space Technology Relevance
The technologies developed directly support NASA's exploration goals:
- **In-Space Manufacturing** - 3D printing techniques applicable to space missions
- **Resource Utilization** - Regolith processing for Mars mission support
- **Autonomous Systems** - Foundation for future planetary exploration robots
- **Harsh Environment Operation** - Dust tolerance and reliability in extreme conditions

## 👥 Team Members

**Team Atlas 2014 Roster:**
- **Eason Smith** - Captain, Project Manager, Electrical/Software Lead
- **Nicholas Reid** - Software Lead, Computer Science
- **Kevin Veerasammy** - Electrical Engineering
- **Devon Simmons** - Mechanical Engineering
- **Pawel Sawicki** - Mechanical Engineering  
- **Sam Huang** - Computer Science
- **Elizabeth Syso** - Mathematics/Computer Science

**Faculty Advisor:** Dr. Haldun Hadimioglu, Computer Engineering Department

## 🌟 Legacy and Lessons Learned

### Technical Innovations
1. **3D Printing Integration** - Demonstrated viability of additive manufacturing for complex robotics
2. **Lightweight Construction** - Proved that innovative materials can outperform traditional approaches
3. **Robust Communication** - Developed reliable wireless protocols for harsh environments
4. **Safety Systems** - Implemented comprehensive fail-safe mechanisms

### Project Management Excellence
- Successfully led interdisciplinary team to competition completion
- Managed complex timeline with hardware, software, and integration phases
- Coordinated budget allocation across mechanical, electrical, and software subsystems
- Implemented systems engineering approach for complex project

## 📞 Contact Information

**Project Lead:** Eason Smith  
**Email:** [contact information]  
**LinkedIn:** [linkedin.com/in/easonsmith](https://linkedin.com/in/easonsmith)  

---

## 📄 License

This project was developed for educational purposes as part of the NASA Robotic Mining Competition. Code and documentation are shared for educational and research purposes.

## 🙏 Acknowledgments

- **NASA** - For hosting this incredible educational competition
- **NYU Tandon School of Engineering** - For facilities and support
- **Dr. Haldun Hadimioglu** - Faculty advisor and mentor
- **Team Atlas Members** - For their dedication and hard work
- **Competition Sponsors** - For supporting student robotics education

---

*This project represents the culmination of a year-long journey in robotics, systems engineering, and space technology development. The lessons learned and innovations developed continue to influence our approach to complex engineering challenges.*