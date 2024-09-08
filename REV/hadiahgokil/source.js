$(document).ready(function () {
    let idCount = 1006;
    let id = "2752-525A-3406C3750-3B8D";
  
    function convertHexToIntArray(hexString) {
      let hexList = hexString.split('-');
      let intList = hexList.map(hex => parseInt(hex, 16));
      return intList;
    }
  
    function convertIntArrayToHex(intList) {
      let hexList = intList.map(value => value.toString(16).toUpperCase());
      return hexList.join('-');
    }
  
    function performOperations(a, b, c, d) {
      let result = [];
      let xorResult = a ^ d;
      result.push(xorResult);
  
      let sumResult = b + a;
      result.push(sumResult);
  
      let modInverse = find_next_class_residue(c, 225925880321);
      result.push(modInverse);
  
      result.push(b);
  
      return result;
    }
  
    
    function find_next_class_residue(num, modulo) {
        let large_prime = 104729 
        return (num * large_prime) % modulo
    }
  
    function generateId() {
      let nums = convertHexToIntArray(id);
      let nextNums = performOperations(nums[0], nums[1], nums[2], nums[3]);
      return convertIntArrayToHex(nextNums);
    }
  
    function register() {
      idCount++;
      let name = $('#name').val();
      let email = $('#email').val();
      id = generateId();
  
      $('#idCount').text(idCount);
      $('#generatedId').text(id);
      $('#outputName').text(name);
      $('#outputEmail').text(email);
  
      $('#result').show();
    }
  
    $('#dataForm').on('submit', function (e) {
      e.preventDefault();
      register();
    });
  
    $('#copyId').on('click', function () {
      const idText = $('#generatedId').text();
      navigator.clipboard.writeText(idText).then(() => {
        alert('ID copied to clipboard!');
      });
    });
  });
  