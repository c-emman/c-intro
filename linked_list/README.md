# C Mini Project: Singly Linked List Library

This project is a small C library that implements a **singly linked list of integers** with a clean API, solid memory handling, and a simple test harness.

Goal: get confident with **pointers**, **structs**, **malloc/free**, and **edge cases**.

---

## Learning Goals

By the end you should be comfortable with:

- Defining linked data structures with `struct`
- Allocating and freeing nodes correctly (`malloc`, `free`)
- Updating pointers safely (head changes, middle deletes, tail cases)
- Designing a small C “library-style” API
- Writing a basic test harness to validate behavior

---

## Project Scope

### Data model
- Singly linked list
- Stores `int` values
- `next` pointer only (no `prev`)

---

## File Layout (suggested)

```text
linked_list/
  README.md
  list.h
  list.c
  main.c        # test harness / demo
  (optional) Makefile
```

---

## API Requirements (v1)

Design the API so it’s easy to use and hard to misuse.

### Types

* Node
* List

Suggestion: use a List struct that holds at least a head pointer.
Optional: also store tail and size if you want (but not required).

### Functions (minimum set)

#### Creation / teardown

* Initialize an empty list
* Free the entire list (all nodes)

#### Insert

* Insert at front (push front)
* Insert at back (push back)

#### Remove

* Remove from front (pop front)
* Remove first matching value

#### Query / utilities

* Find first matching value (or node)
* Compute list length (or return stored size)
* Print list (debug helper)

⸻

## Functional Requirements

### General

* No memory leaks (every malloc must be paired with a free)
* No use-after-free
* No invalid reads/writes
* Correct behavior for empty list operations (must not crash)

### Edge Cases You Must Handle

* Insert into empty list
* Remove from empty list
* Remove head node
* Remove a middle node
* Remove tail node
* Remove a value that doesn’t exist
* Multiple nodes with the same value (remove-first should remove only the first)

⸻

## Return Values / Errors

Pick a consistent approach and use it everywhere:

* For operations that might fail (e.g., pop from empty list), return a status code (e.g., 0/1) and write the removed value into an output parameter, OR return a sentinel value and document it.

Keep it consistent across the API.

⸻

## Test Harness Requirements (main.c)

Write a main.c that runs a sequence of operations and prints results clearly.

### Minimum test scenarios

1. Empty list

* Print it
* Try pop/remove (should not crash)

2. Push front

* Add: 3, 2, 1 (so list becomes 1 -> 2 -> 3)
* Print after each insert

3. Push back

* Add: 4, 5
* List should become 1 -> 2 -> 3 -> 4 -> 5

4. Remove first matching

* Remove 1 (head)
* Remove 3 (middle)
* Remove 5 (tail)
* Remove 99 (missing)

5. Pop front repeatedly

* Pop until empty
* One extra pop on empty (should not crash)

6. Free list

* Free at the end
* If you can, run with a leak checker

⸻

## “Done” Criteria

You’re done when:

* All operations work for the edge cases above
* You can run your test harness and the printed outputs make sense
* You’ve checked memory safety (at least by careful review; ideally with a tool)
* Your code is separated into .h and .c cleanly

⸻

## Optional Stretch Goals (pick 1–2)

* Store tail to make push_back O(1)
* Store size to make length O(1)
* Add insert_after(value_to_find, new_value)
* Add reverse(list)
* Add clear(list) separate from free(list)
* Convert to a generic list using void * (only if you want extra challenge)

⸻

## Notes / Constraints

* Keep it singly linked for this project
* Keep it int-only for this project
* Focus on correctness and clean pointer updates over fancy features

⸻

## Suggested Workflow

1. Define structs + list init
2. Implement push_front
3. Implement pop_front
4. Implement push_back
5. Implement remove_first(value)
6. Implement find + length + print
7. Write the test harness and iterate until all cases pass
8. Final cleanup: naming consistency, comments, header hygiene