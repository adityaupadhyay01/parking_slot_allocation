function park() {
    let vehicle = document.getElementById("vehicle").value;

    fetch("http://localhost:3000/park", {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify({ vehicle })
    })
    .then(res => res.text())
    .then(data => alert(data));
}

function exitVehicle() {
    let vehicle = document.getElementById("vehicle").value;

    fetch("http://localhost:3000/exit", {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify({ vehicle })
    })
    .then(res => res.text())
    .then(data => alert(data));
}