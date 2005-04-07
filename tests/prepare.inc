<?php

// Drop the test table, in case it exists
$drop = 'DROP TABLE animals';
$result = @db2_exec($conn, $drop);

// Create the test table
$create = 'CREATE TABLE animals (id INTEGER, breed VARCHAR(32), name CHAR(16), weight DECIMAL(7,2))';
$result = db2_exec($conn, $create);

// Populate the test table
$animals = array(
    array(0, 'cat', 'Pook', 3.2),
    array(1, 'dog', 'Peaches', 12.3),
    array(2, 'horse', 'Smarty', 350.0),
    array(3, 'gold fish', 'Bubbles', 0.1),
    array(4, 'budgerigar', 'Gizmo', 0.2),
    array(5, 'goat', 'Rickety Ride', 9.7),
    array(6, 'llama', 'Sweater', 150)
);

/* Use this approach once prepare/execute work properly
$insert = 'INSERT INTO animals (id, breed, name, weight) VALUES (?, ?, ?, ?)';
$stmt = db2_prepare($conn, $insert);
if ($stmt) {
    foreach ($animals as $animal) {
        $result = db2_execute($stmt, $animal);
    }
}
*/

foreach ($animals as $animal) {
    db2_exec($conn, "INSERT INTO animals (id, breed, name, weight) VALUES (" .
        $animal[0] . ", '" . 
        $animal[1] . "', '" . 
        $animal[2] . "', " . 
        $animal[3] . ")");
}

?>