<div align="center">
  <h1>OpenMP Seminar 2025</h1>
  <p>Hands-on introduction to parallel programming with OpenMP</p>
  
  <!-- Badges -->
  <p>
    <img src="https://img.shields.io/badge/C-OpenMP-orange.svg" alt="C OpenMP" />
    <img src="https://img.shields.io/badge/Parallelization-MultiThreading-purple.svg" alt="Parallelization" />
  </p>
  
  <!-- Links -->
  <h4>
    <a href="#examples">View Examples</a>
    <span> · </span>
    <a href="#quick-start">Quick Start</a>
  </h4>
</div> 

---

## About the Project

- This repository contains materials and code examples from a lecture I delivered about **OpenMP**, as part of a seminar I attended on **Parallelization and Program Optimization**.  
- The lecture covered OpenMP fundamentals step by step:  
  - Parallel regions  
  - Synchronization (critical, atomic, barrier)  
  - Loop scheduling and reductions  
  - Worksharing constructs (for, sections, single, master)  
  - Tasks and advanced usage  
- In addition, the repository includes a **MATMUL** folder with matrix multiplication implementations (classic and Strassen) parallelized with OpenMP tasks.

---

## Examples

<details>
<summary>Hello World & Pi Approximation</summary>
<p><em>Getting started with OpenMP and exploring scaling issues</em></p>

**Features:**
- `hello_world.c` – simple parallel region with thread IDs  
- `pi_spmd_simple.c` – parallel numerical integration (SPMD style)  
- `pi_spmd_final.c` – fixes false sharing, demonstrates critical & atomic sections  
- `pi_loop.c` – loop-based parallelism with scheduling & reduction  

</details>

<details>
<summary>Synchronization & Worksharing</summary>
<p><em>Understanding control of data races and workload distribution</em></p>

**Features:**
- Critical vs. atomic vs. barrier  
- Worksharing constructs: for, single, sections, master  
- Scheduling policies: static, dynamic, guided, runtime  

</details>

<details>
<summary>Matrix Multiplication (MATMUL)</summary>
<p><em>Parallel matrix multiplication with tasks</em></p>

**Features:**
- `matmul.c` – classic matrix multiplication with OpenMP  
- Strassen’s matrix multiplication with divide-and-conquer  
- OpenMP **tasks** for recursive subproblems  
- Time analysis and performance comparison  

[Explore the MATMUL examples](https://github.com/orishlach/openMP/Matmul)

</div>
</details>

---

## Quick Start

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/openmp-seminar.git
   cd openmp-seminar
   ```

2. Compile examples with GCC and OpenMP flag:
   ```bash
   gcc -fopenmp hello_world.c -o hello_world
   gcc -fopenmp pi_loop.c -o pi_loop
   gcc -fopenmp MATMUL/matmul.c -o matmul
   ```

3. Run executables:
   ```bash
   ./hello_world
   ./pi_loop
   ./matmul
   ```

4. Control the number of threads:
   ```bash
   export OMP_NUM_THREADS=4
   ```

---

## References

- [OpenMP Official Tutorial](https://github.com/tgmattso/OpenMP_intro_tutorial)
- [Parallel programming with OpenMP
by Mr Orian Louant](https://indico.cism.ucl.ac.be/event/72/?print=1)  
- Seminar slides: [Hands-on Introduction to OpenMP](https://github.com/orishlach/openMP/blob/main/Hands-on%20Introduction%20to%20OpenMP.pdf)
