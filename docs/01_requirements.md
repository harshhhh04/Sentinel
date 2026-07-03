# Document Information

Document: System Requirements

Version: 0.1

Status: Draft

Last Updated: 2026-07-03

Owner: Harshit Mohindra

Related Documents:

- MISSION.md
- ROADMAP.md

## 1. Purpose

Modern embedded systems are becoming increasingly complex.

Whether deployed in wearable devices, electric vehicles, industrial equipment or medical systems, firmware is expected to continuously observe system behavior, detect abnormal conditions, record meaningful diagnostics and communicate critical information while remaining reliable, efficient and minimally intrusive.

Sentinel exists to explore and develop the engineering principles, firmware architecture and platform services required to build such systems.

Rather than solving a single product-specific problem, Sentinel aims to establish a reusable foundation for modern embedded firmware that prioritizes modularity, reliability, maintainability and observability.

Sentinel is designed to answer one question:
"How can an embedded system understand the system it protects without becoming part of the problem?"

## 2. Scope

Sentinel is a reusable embedded firmware platform designed to provide the core infrastructure required for modern embedded systems.

The platform focuses on hardware abstraction, diagnostics, event-driven communication, power-aware operation, logging, configuration management and modular firmware architecture.

Sentinel intentionally remains independent of any specific product domain. Whether deployed within a wearable device, an electric vehicle, an industrial controller or another embedded application, the platform itself remains unchanged. Product-specific functionality belongs exclusively to the application layer.

Sentinel does not define hardware products, user interfaces, cloud services or machine learning models. Instead, it provides the engineering foundation upon which such systems can be built.

The hardware used to develop Sentinel is considered an implementation detail rather than a defining characteristic of the platform. Sentinel is designed to evolve across multiple microcontroller families without changing its architectural principles.

## 3. Design Philosophy

Every engineering decision within Sentinel shall follow the First Law of Sentinel.

> Sentinel observes the system.
> It never becomes the problem.

The following principles govern the design and evolution of Sentinel.

------------------------------------------------

1. Understanding Before Implementation

Every architectural decision, interface and implementation must be understood before it is accepted into Sentinel.

If a feature cannot be explained, justified and debugged, it does not belong in Sentinel.

------------------------------------------------

2. Separation of Concerns

The platform provides infrastructure.

Applications provide behavior.

Product-specific logic shall remain independent from the platform.

------------------------------------------------

3. Hardware Independence

Hardware enables Sentinel.

It does not define Sentinel.

The architecture shall remain portable across multiple microcontroller families.

------------------------------------------------

4. Observability First

Sentinel shall make system behavior observable before attempting to optimize or automate it.

Sentinel shall expose sufficient diagnostics to understand system behavior and failures.

------------------------------------------------

5. Simplicity Over Cleverness

Simple, maintainable solutions are preferred over unnecessarily clever implementations.

------------------------------------------------

6. Measure Before Optimizing

Performance optimizations shall be guided by evidence rather than assumptions.

------------------------------------------------

7. Incremental Evolution

Sentinel shall evolve through small, verifiable improvements rather than large rewrites.

------------------------------------------------

8. Documentation Evolves With Implementation

Documentation and implementation shall remain synchronized throughout development.

------------------------------------------------

9. Reusability

Modules should solve engineering problems beyond a single application whenever practical.   

## 4. Stakeholders

Sentinel is built for engineers who believe that understanding a system is the first step toward improving it.

Its primary purpose is to serve embedded engineers, students, researchers and enthusiasts by providing a reusable firmware platform that emphasizes observability, reliability and sound engineering principles.

Rather than replacing engineering decisions, Sentinel provides the information and infrastructure required for engineers to make better ones.

Anyone building embedded systems who values understanding over assumption is part of Sentinel's intended audience.

Sentinel exists to help engineers understand their systems before those systems fail them.

## 5. System Overview

Sentinel is designed as a reusable firmware platform that continuously observes the state of an embedded system without directly controlling its behavior. Its responsibility is to collect observations, understand their significance within the context provided by the application, and communicate meaningful information to the appropriate system components.

At its core, Sentinel follows an event-driven architecture. Rather than tightly coupling modules together, information flows through events that allow independent components to react without creating unnecessary dependencies. This approach improves modularity, maintainability and scalability while keeping the platform independent of any specific application domain.

Sentinel transforms raw observations into meaningful system events without assuming responsibility for application-specific decisions.

The overall flow of information within Sentinel can be summarized as:

Observation Source
↓
Timestamp
↓
Validation
↓
Event Generation
↓
Platform Services
    ├── Logger
    ├── Diagnostics
    ├── Storage
    ├── Communication
    └── Application Layer

Observation sources are intentionally kept generic. Data may originate from sensors, communication interfaces or other hardware peripherals. Sentinel does not distinguish between individual hardware devices; it only processes observations provided by the underlying hardware abstraction layer.

Validation determines whether an observation is meaningful within the context defined by the application. Sentinel itself does not define what is considered "safe" or "unsafe". Product-specific decisions remain the responsibility of the application layer, ensuring that the platform remains reusable across different domains.

The platform communicates information through events rather than direct module interactions. Logging, diagnostics, communication and storage subscribe to relevant events and operate independently. This minimizes coupling between modules and allows Sentinel to evolve without requiring widespread architectural changes.

The primary outputs produced by Sentinel include:

- Diagnostic events
- System logs
- Health information
- Alerts generated by the application layer
- Communication packets
- Persistent diagnostic records

By separating observation, interpretation and communication, Sentinel remains faithful to its First Law:

> Sentinel observes the system.
> It never becomes the problem.

## 6. Functional Requirements

The following functional requirements define the core capabilities that Sentinel must provide. These requirements describe *what* the platform is expected to do, independent of any specific hardware, microcontroller or application domain.

### Observation

**FR-001**

**Requirement:**  
Sentinel shall receive observations from the Hardware Abstraction Layer (HAL).

**Priority:** Critical

**Rationale:**  
All platform functionality begins with receiving observations from the underlying hardware while remaining independent of specific sensors or peripherals.

---

**FR-002**

**Requirement:**  
Sentinel shall timestamp every received observation before further processing.

**Priority:** Critical

**Rationale:**  
Accurate timestamps are essential for diagnostics, event correlation and post-event analysis.

---

**FR-003**

**Requirement:**  
Sentinel shall perform integrity checks before processing observations.

**Priority:** Critical

**Rationale:**  
Invalid, corrupted or physically impossible observations shall be detected before entering the processing pipeline.

---

### Analysis

**FR-004**

**Requirement:**  
Sentinel shall evaluate observations using application-defined validation rules.

**Priority:** Critical

**Rationale:**  
Validation logic varies across applications and shall remain configurable rather than hardcoded within the platform.

---

**FR-005**

**Requirement:**  
Sentinel shall distinguish routine observations from meaningful system events.

**Priority:** Critical

**Rationale:**  
Only observations that represent meaningful state changes or diagnostic significance shall progress into the event system.

---

**FR-006**

**Requirement:**  
Sentinel shall remain independent of application-specific thresholds, safety limits and business logic.

**Priority:** Critical

**Rationale:**  
Application-specific decisions remain outside the platform to preserve reusability across domains.

---

### Event Management

**FR-007**

**Requirement:**  
Sentinel shall generate events from validated observations that carry diagnostic significance.

**Priority:** Critical

**Rationale:**  
Events form the primary communication mechanism between platform modules.

---

**FR-008**

**Requirement:**  
Platform services shall communicate through events rather than direct module dependencies whenever practical.

**Priority:** High

**Rationale:**  
Loose coupling improves maintainability, modularity and portability.

---

### Diagnostics

**FR-009**

**Requirement:**  
Sentinel shall record diagnostic events throughout system operation.

**Priority:** High

**Rationale:**  
Diagnostic information enables troubleshooting, system monitoring and post-event analysis.

---

**FR-010**

**Requirement:**  
Sentinel shall preserve contextual information surrounding critical events.

**Priority:** High

**Rationale:**  
Maintaining observations immediately before and after a critical event significantly improves fault diagnosis.

---

**FR-011**

**Requirement:**  
Sentinel shall provide sufficient diagnostic information to explain why a critical event occurred whenever possible.

**Priority:** High

**Rationale:**  
Sentinel should assist engineers in understanding failures rather than simply reporting them.

---

### Communication

**FR-012**

**Requirement:**  
Sentinel shall expose events and diagnostic information through available communication interfaces.

**Priority:** High

**Rationale:**  
The communication mechanism is implementation-specific, but the information exposed by Sentinel shall remain consistent.

---

**FR-013**

**Requirement:**  
Communication services shall remain independent of the platform core.

**Priority:** Medium

**Rationale:**  
The platform shall support different communication technologies without architectural changes.

---

### Storage

**FR-014**

**Requirement:**  
Sentinel shall maintain a rolling history of recent observations.

**Priority:** High

**Rationale:**  
A rolling history provides valuable diagnostic context while minimizing storage usage.

---

**FR-015**

**Requirement:**  
Sentinel shall preserve observations immediately before and after critical events.

**Priority:** High

**Rationale:**  
Critical events should capture sufficient surrounding context to enable accurate diagnosis.

---

**FR-016**

**Requirement:**  
Sentinel shall support persistent storage of critical diagnostic records.

**Priority:** Medium

**Rationale:**  
Critical system events should remain available after resets or power cycles whenever supported by the target hardware.

## 7. Non-Functional Requirements

### Reliability

**NFR-001**

**Requirement:**  
Critical observations shall always take precedence over non-critical platform services.

**Priority:** Critical

**Rationale:**  
The platform must prioritize system safety and diagnostics over secondary functions such as communication or logging.

---

**NFR-002**

**Requirement:**  
Failure of one platform service shall not prevent Sentinel from continuing to observe the system.

**Priority:** Critical

**Rationale:**  
Platform modules shall fail independently whenever practical.

---

### Fault Tolerance

**NFR-003**

**Requirement:**  
Sentinel shall preserve sufficient crash context to support post-reset fault analysis.

**Priority:** Critical

**Rationale:**  
Understanding why a failure occurred is fundamental to Sentinel's purpose.

---

### Maintainability

**NFR-004**

**Requirement:**  
Platform modules shall remain loosely coupled through event-driven communication.

**Priority:** High

**Rationale:**  
Reducing module dependencies improves maintainability and long-term scalability.

---

### Portability

**NFR-005**

**Requirement:**  
The platform shall remain independent of any specific microcontroller family.

**Priority:** High

**Rationale:**  
Porting Sentinel should primarily require hardware abstraction changes rather than platform redesign.

---

### Performance

**NFR-006**

**Requirement:**  
Performance optimizations shall never compromise maintainability without measurable benefit.

**Priority:** Medium

**Rationale:**  
Optimization decisions shall be driven by evidence rather than assumption.

---

### Observability

**NFR-007**

**Requirement:**  
Sentinel shall expose sufficient diagnostic information to explain significant system behaviour whenever practical.

**Priority:** High

**Rationale:**  
A system that cannot explain its behaviour cannot be effectively maintained or trusted.

---

### Resource Efficiency

**NFR-008**

**Requirement:**  
Sentinel shall minimize processor, memory and power overhead while fulfilling its monitoring responsibilities.

**Priority:** High

**Rationale:**  
Sentinel must remain faithful to its First Law by observing the system without becoming a burden on it.

---

### Documentation

**NFR-009**

**Requirement:** 
Every architectural decision shall be documented before implementation whenever it introduces a new platform concept.

**Priority:** Medium

**Rationale:**
Long-term maintainability depends as much on preserving engineering knowledge as preserving source code.

## 8. Hardware Requirements

The hardware platform hosting Sentinel shall provide the capabilities necessary to support reliable system observation, diagnostics and communication while remaining independent of any specific microcontroller family or hardware vendor.

### Processing

**HR-001**

**Requirement:**  
The target platform shall support interrupt-driven operation.

**Priority:** Critical

**Rationale:**  
Timely response to hardware events is essential for accurate monitoring and diagnostics.

---

**HR-002**

**Requirement:**  
The target platform shall provide hardware timers suitable for periodic sampling, scheduling and timeout management.

**Priority:** Critical

**Rationale:**  
Reliable timing is fundamental to observation, event generation and diagnostics.

---

**HR-003**

**Requirement:**  
The target platform shall provide a watchdog mechanism capable of recovering the system from unrecoverable software faults.

**Priority:** Critical

**Rationale:**  
Sentinel must recover safely from unexpected failures while preserving diagnostic information whenever possible.

---

**HR-004**

**Requirement:**  
The target platform shall provide sufficient processing resources to execute Sentinel without compromising application responsiveness.

**Priority:** High

**Rationale:**  
Sentinel shall observe the system without becoming a source of performance degradation.

---

### Memory

**HR-005**

**Requirement:**  
The target platform shall provide sufficient volatile memory for runtime operation, event queues and temporary diagnostic data.

**Priority:** Critical

**Rationale:**  
Runtime services require dedicated working memory for reliable operation.

---

**HR-006**

**Requirement:**  
The target platform shall provide non-volatile storage for configuration data and persistent diagnostic records.

**Priority:** High

**Rationale:**  
Critical information shall remain available after resets or power loss whenever supported by the hardware.

---

### Peripheral Interfaces

**HR-007**

**Requirement:**  
The target platform shall provide general-purpose input/output (GPIO) capabilities.

**Priority:** Critical

**Rationale:**  
GPIO forms the foundation for interfacing with external hardware.

---

**HR-008**

**Requirement:**  
The target platform shall support standard embedded communication peripherals such as UART, SPI and I²C.

**Priority:** High

**Rationale:**  
These interfaces enable communication with sensors, peripherals and debugging tools.

---

**HR-009**

**Requirement:**  
The target platform should provide analog-to-digital conversion capabilities where analog observations are required.

**Priority:** Medium

**Rationale:**  
Many embedded systems rely on analog measurements for monitoring system health.

---

### Communication

**HR-010**

**Requirement:**  
The target platform shall provide at least one communication interface capable of exporting diagnostic information.

**Priority:** High

**Rationale:**  
Sentinel must communicate events and diagnostics without depending on a specific protocol.

---

### Debug Support

**HR-011**

**Requirement:**  
The target platform shall provide a hardware programming and debugging interface.

**Priority:** Critical

**Rationale:**  
Firmware development, validation and fault analysis require reliable debugging capabilities.

---

**HR-012**

**Requirement:**  
The target platform shall provide a hardware reset mechanism.

**Priority:** High

**Rationale:**  
Hardware recovery shall remain possible regardless of software state.

---

### Timing

**HR-013**

**Requirement:**  
The target platform shall provide a stable system clock suitable for deterministic operation.

**Priority:** Critical

**Rationale:**  
Accurate timing is essential for timestamp generation, scheduling and event correlation.

---

### Power

**HR-014**

**Requirement:**  
The target platform shall support power management features appropriate for the target application.

**Priority:** High

**Rationale:**  
Sentinel shall minimize its impact on overall system power consumption.

---

### Portability

**HR-015**

**Requirement:**  
Sentinel shall rely exclusively on hardware abstraction layers for hardware-specific functionality.

**Priority:** Critical

**Rationale:**  
Platform portability shall be achieved by isolating hardware dependencies from the platform core.

## 9. Firmware Requirements

The Sentinel firmware shall provide a modular and reusable software architecture that separates hardware-specific functionality from platform services and application logic. Each module shall have a clearly defined responsibility and communicate through well-defined interfaces.

### Hardware Abstraction Layer

**FW-001**

**Requirement:**  
The firmware shall isolate all hardware-specific operations within the Hardware Abstraction Layer (HAL).

**Priority:** Critical

**Rationale:**  
Hardware abstraction enables platform portability and simplifies migration between microcontroller families.

---

### Observation Management

**FW-002**

**Requirement:**  
The firmware shall provide a mechanism for receiving observations from the Hardware Abstraction Layer.

**Priority:** Critical

**Rationale:**  
Observations form the entry point of the Sentinel processing pipeline.

---

**FW-003**

**Requirement:**  
The firmware shall timestamp and validate observations before further processing.

**Priority:** Critical

**Rationale:**  
Accurate and trustworthy observations are essential for reliable diagnostics.

---

### Event Management

**FW-004**

**Requirement:**  
The firmware shall provide an event management system responsible for distributing events throughout the platform.

**Priority:** Critical

**Rationale:**  
Events provide loose coupling between platform modules.

---

**FW-005**

**Requirement:**  
Platform modules shall communicate through the Event Manager rather than direct dependencies whenever practical.

**Priority:** High

**Rationale:**  
Reducing module coupling improves maintainability and scalability.

---

### Logging

**FW-006**

**Requirement:**  
The firmware shall provide a centralized logging service.

**Priority:** High

**Rationale:**  
Centralized logging provides consistent diagnostics across the platform.

---

### Diagnostics

**FW-007**

**Requirement:**  
The firmware shall provide diagnostic services capable of reporting system health and fault information.

**Priority:** High

**Rationale:**  
Diagnostic information enables engineers to understand system behaviour and failures.

---

### Storage

**FW-008**

**Requirement:**  
The firmware shall provide storage services for configuration data and diagnostic records.

**Priority:** High

**Rationale:**  
Persistent storage enables post-reset analysis and configuration retention.

---

### Communication

**FW-009**

**Requirement:**  
The firmware shall provide an interface for exporting diagnostic information through supported communication mechanisms.

**Priority:** High

**Rationale:**  
Communication technologies may change without affecting the platform architecture.

---

### Power Management

**FW-010**

**Requirement:**  
The firmware shall support power-aware operation while minimizing its impact on the monitored system.

**Priority:** High

**Rationale:**  
Sentinel shall remain faithful to its First Law by minimizing resource consumption.

---

### Configuration

**FW-011**

**Requirement:**  
The firmware shall support configurable operating parameters without requiring modification of platform source code.

**Priority:** Medium

**Rationale:**  
Different applications require different operating characteristics while sharing the same platform.

---

### Application Interface

**FW-012**

**Requirement:**  
The firmware shall expose a well-defined interface through which application-specific functionality can interact with Sentinel.

**Priority:** Critical

**Rationale:**  
Clear separation between platform and application logic preserves reusability.

## 10. Constraints

Sentinel shall operate under the following constraints:

- Platform code shall remain independent of any specific application domain.
- Hardware-specific implementations shall remain isolated within the Hardware Abstraction Layer.
- Critical monitoring shall not be blocked by lower-priority platform services.
- Platform modules shall communicate through events whenever practical.
- Sentinel shall minimize processor, memory and power overhead.
- Architectural decisions shall prioritize maintainability over premature optimization.
- The implementation shall remain portable across supported hardware platforms.
- Sentinel shall observe system behaviour without directly controlling application-specific actions unless explicitly configured to do so.

## 11. Assumptions

Sentinel assumes the following conditions:

- The Hardware Abstraction Layer provides valid hardware access.
- The application layer defines domain-specific validation rules and thresholds.
- The target platform provides sufficient processing and memory resources.
- A stable timing source is available.
- Communication interfaces are available when external diagnostics are required.
- Persistent storage is available when diagnostic retention is enabled.
- The monitored application determines appropriate responses to Sentinel events.

## 12. Future Scope

Future versions of Sentinel may include:

- Machine learning assisted anomaly detection.
- Predictive maintenance capabilities.
- OTA firmware update support.
- Multi-node distributed monitoring.
- Cloud-connected diagnostics.
- Secure event storage.
- Remote configuration management.
- Digital twin integration.
- Additional communication protocols.
- Functional safety extensions.

## 13. Glossary

| Term | Definition |
|------|------------|
| Observation | Raw information received from the Hardware Abstraction Layer. |
| Validation | Verification that an observation is meaningful for the application. |
| Event | A validated observation carrying diagnostic significance. |
| Diagnostic Record | Information describing system behaviour or faults. |
| HAL | Hardware Abstraction Layer providing platform-independent hardware access. |
| Platform | The reusable core firmware provided by Sentinel. |
| Application Layer | Product-specific logic built on top of Sentinel. |
| Critical Event | An event requiring immediate attention due to abnormal system behaviour. |
| Context | Supporting observations surrounding a significant event used for diagnosis. |