# Smart Water Conservation System (SDG 6)

A console-based C application designed to monitor daily water usage across campus buildings, identify peak-demand zones, evaluate consumption against daily target budgets, and estimate potential water savings.

---

## Project Details
* **Project Group:** Group 1 (SOCS Batch B-29)
* **Subject:** Problem Solving & Programming in C
* **SDG Alignment:** UN SDG 6 — Clean Water and Sanitation
* **Submitted To:** Mr. Sourabh Raghuvanshi

### Group Members
| Student Name | SAP ID | Batch |
| :--- | :---: | :---: |
| Nishchal | 590033560 | B-29 |
| Ojas Sachan | 590035015 | B-29 |
| Priyanshu | 590032331 | B-29 |
| Atharv | 590034487 | B-29 |
| Nikhil | 590034686 | B-29 |

---

## Problem Addressed
In large residential campuses, hostels, and academic blocks, substantial volumes of clean water are wasted daily due to unmonitored consumption and undetected leaks. Without building-level usage tracking, administrators cannot identify high-consumption hotspots or set realistic conservation targets.

This program provides a lightweight, structured tracking tool that turns raw daily meter readings (in litres) into actionable conservation insights.

---

## Key Features
* **Multi-Location Tracking:** Logs daily water consumption (in litres) for up to 50 distinct campus zones using arrays.
* **Input Validation:** Automatically rejects negative consumption readings, invalid location counts, and out-of-range reduction percentages.
* **Statistical Summary:** Computes total water consumed and mean usage per location.
* **Peak Hotspot Detection:** Automatically identifies the facility with the highest water footprint.
* **Target Evaluation & Savings Estimator:** Compares total consumption against a user-defined daily budget and calculates projected savings under a proposed reduction percentage.

---

## C Programming Concepts Used
* 1D & 2D Arrays (`float litres[]`, `char locations[][]`)
* User-Defined Functions (`calculateTotal`, `findHighestUsageIndex`, `displayReport`)
* Loops (`for`, `do-while` for input validation)
* Conditional Statements (`if`, `else if`, `else`)
* Formatted Console I/O (`printf`, `scanf`)

---

## How to Compile & Run

1. **Compile the source code using GCC:**
   ```bash
   gcc water_conservation.c -o water_conservation
