const rl = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

function PolynomialExpansion(str) {
  // works for expanding more than 2 polynomials too

  var variable = str.match(/[a-zA-Z]/gi)[0];

  function clean(str, arr) {
    // converts str = "ax^b + cx + d" into [[a, c, d], [b, 1 0]] and store into arr, where x is variable
    var c = 0; // coefficient index
    var e = 1; // exponential index
    var regex = new RegExp(
      "(\\+|-)?[0-9]+" + variable + "?(\\^(\\+|-)?[0-9]+)?",
      "i"
    );
    var match = str.match(regex); // find anything of the form ax^b
    var term = match[0];

    var ce; // store a and b into arr
    if (term.indexOf("^") !== -1) ce = term.split(variable + "^").map(Number);
    else {
      ce = term.split(variable).map(Number);
      if (term.indexOf(variable) !== -1) ce[1] = 1; // if x to power of 1
    }
    if (ce.length === 1) ce.push(0); // if no x

    arr[c].push(ce[c]);
    arr[e].push(ce[e]);

    if (str.length === match[0].length)
      // if this is the last term, then done
      return;

    clean(str.substring(match.index + match[0].length), arr); // continue cleaning, excluding current term
  }

  function expand(arr) {
    // takes an array, each element being an array in format returned by clean function,
    // and returns expanded polynomial in the same format
    if (arr.length === 1)
      // if arr only has 1 polynomial, then done
      return arr[0];

    var first = arr[0];
    var second = arr[1];
    var result = [[], []];

    arr.shift(); // remove first element
    arr[0] = result; // replace the new first element with result of expansion of first & second

    for (var i = 0; i < first[0].length; i++) {
      for (var j = 0; j < second[0].length; j++) {
        var rCoeff = first[0][i] * second[0][j]; // coefficient
        var rExp = first[1][i] + second[1][j]; // exponent

        var rCoeffIndex = result[1].indexOf(rExp);
        if (rCoeffIndex === -1) {
          result[0].push(rCoeff);
          result[1].push(rExp);
        } else {
          result[0][rCoeffIndex] += rCoeff;
          if (result[0][rCoeffIndex] === 0) {
            // remove term if coefficient is 0
            result[0].splice(rCoeffIndex, 1);
            result[1].splice(rCoeffIndex, 1);
          }
        }
      }
    }

    // sort by exponent
    var sortedExp = result[1].slice().sort(function (a, b) {
      return b - a;
    });
    var sortedCoeff = result[0].slice();
    sortedCoeff.forEach(function (element, index, array) {
      array[index] = result[0][result[1].indexOf(sortedExp[index])];
    });
    arr[0] = [sortedCoeff, sortedExp];

    return expand(arr);
  }

  // take input string, convert to array
  var strArr = str.split(")(").map(function (a) {
    return a.replace(/[\(\)]/gi, "");
  });
  var arr = [];
  for (var i = 0; i < strArr.length; i++) {
    if (arr[i] === undefined) arr[i] = [[], []];
    clean(strArr[i], arr[i], variable);
  }

  // expand using array
  var resultArr = expand(arr);

  // convert to proper string
  var expanded = "";
  for (var i = 0; i < resultArr[0].length; i++) {
    var coeff = resultArr[0][i];
    var exp = resultArr[1][i];

    if (expanded.length !== 0 && coeff > 0) expanded += "+";
    if (Math.abs(coeff) > 1) expanded += coeff;

    if (exp !== 0) {
      expanded += variable;
      if (exp !== 1) expanded += "^" + exp;
    }
  }

  return expanded;
}

rl.question("Enter the string ", (data) => {
  console.log(PolynomialExpansion(data));
  rl.close();
});
