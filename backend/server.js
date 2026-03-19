const express = require("express");
const { exec } = require("child_process");
const cors = require("cors");

const app = express();
app.use(express.json());
app.use(cors());

app.post("/park", (req, res) => {
    const vehicle = req.body.vehicle;

    exec(`../c_engine/parking.exe park ${vehicle}`, (err, stdout) => {
        if (err) return res.send("Error");
        res.send(stdout);
    });
});

app.post("/exit", (req, res) => {
    const vehicle = req.body.vehicle;

    exec(`../c_engine/parking.exe exit ${vehicle}`, (err, stdout) => {
        if (err) return res.send("Error");
        res.send(stdout);
    });
});

app.listen(3000, () => console.log("Server running on port 3000"));