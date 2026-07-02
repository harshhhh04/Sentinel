# Mission

> "Don't build projects.
> Build engineering capability."

---

## Why this repository exists

Modern embedded systems are becoming increasingly complex.

Whether it is an electric vehicle, a wearable, an industrial controller, a medical device or a robot, the underlying firmware faces many of the same engineering challenges:

- Reliable communication
- Power management
- Fault diagnostics
- Real-time scheduling
- Firmware updates
- Modular software architecture
- Debugging under constrained hardware
- Long-term maintainability

Most student projects demonstrate features.

Very few demonstrate engineering.

This repository exists to bridge that gap.

---

## The Problem

During my internships I realized something.

The hardest part of embedded engineering isn't writing code.

It is making engineering decisions.

Questions like:

- Why should this task have higher priority?
- Should this interrupt wake the MCU?
- Is polling acceptable here?
- How should failures be reported?
- How can firmware be updated safely?
- What happens after an unexpected power loss?
- Can another engineer understand this code six months later?

Those questions rarely appear in university projects.

Yet they define production firmware.

---

## My Goal

This repository is my attempt to think like a firmware engineer rather than a student.

Instead of building isolated projects, I am building a production-inspired embedded firmware platform that grows through real applications and real engineering problems.

Every feature added to this repository must answer four questions:

1. What problem does it solve?
2. Why is this implementation chosen?
3. What trade-offs exist?
4. How would this behave in production?

If a feature cannot justify its existence, it doesn't belong here.

---

## Engineering Principles

This repository values:

- Simplicity over cleverness
- Reliability over features
- Documentation over assumptions
- Architecture over hacks
- Reusability over duplication
- Measured decisions over guesswork
- Continuous improvement over perfection

---

## Engineering Integrity

Sentinel is built using modern engineering tools, including AI.

AI is treated as an engineering assistant, not an engineering replacement.
It helps challenge assumptions, review designs, accelerate research, and explain unfamiliar concepts.
The final engineering decisions remain my responsibility.

However, every architectural decision, algorithm, interface, and implementation merged into this repository must be something I can independently explain, justify, and defend.

If I cannot explain a piece of code on a whiteboard without external help, it does not belong in Sentinel.

The goal of this repository is not to demonstrate how quickly software can be generated.

The goal is to demonstrate how deeply embedded systems can be understood.

---

## What this is NOT

This is not:

- An Arduino tutorial
- A semester-only project
- A collection of random examples
- A copy of existing firmware libraries
- A showcase of buzzwords

Every module must solve a real engineering problem.

---

## Long-Term Vision

The repository will evolve continuously.

New application domains may include:

- Electric Vehicle Diagnostics
- Wearable Devices
- Industrial Monitoring
- Medical Electronics
- Robotics
- Smart Sensor Platforms

The application may change.

The engineering principles will not.

---

## Success

I won't measure success by GitHub stars.

Success is when an experienced firmware engineer opens this repository and thinks:

> "I'd enjoy discussing this architecture with the person who built it."

That is the standard this repository is aiming for.

---

## A promise to my future self

> "Every commit should leave Sentinel better than I found it."

---

# The Laws of Sentinel

## First Law

Sentinel observes the system.

It never becomes the problem.

---

## Second Law

Every engineering decision must be explainable.

---

## Third Law

Every module must earn its place.
