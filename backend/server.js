const express = require("express");
const { exec } = require("child_process");
const cors = require("cors");
const path = require("path");

const app = express();
app.use(express.json());
app.use(cors());

// absolute path to exe
const exePath = path.join(__dirname, "../c_engine/parking.exe");

// PARK
app.post("/park", (req, res) => {
    const vehicle = req.body.vehicle;

    exec(`"${exePath}" park ${vehicle}`, (err, stdout, stderr) => {
        if (err) {
            console.log("ERROR:", err);
            console.log("STDERR:", stderr);
            return res.send("Error running C program");
        }
        res.send(stdout);
    });
});

// EXIT
app.post("/exit", (req, res) => {
    const vehicle = req.body.vehicle;

    exec(`"${exePath}" exit ${vehicle}`, (err, stdout, stderr) => {
        if (err) {
            console.log("ERROR:", err);
            console.log("STDERR:", stderr);
            return res.send("Error running C program");
        }
        res.send(stdout);
    });
});

app.listen(3000, () => console.log("Server running on port 3000"));